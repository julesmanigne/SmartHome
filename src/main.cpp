#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
#include <string>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//========================================================================================

#define LED1 19
#define LED2 18
#define LED3 15

float TEMPERATURE_CHAMBRE = 0.0;
float PRESSION_CHAMBRE = 0.0;
float ALTITUDE_CHAMBRE = 0.0;
//========================================================================================

#define SSID "TribuM"           // WiFi name
#define PASSWORD "Garennen1j1@" // WiFi password

// #define SSID "iPhone de Jules"
// #define PASSWORD "Ataturk123"

// #define SSID "Dolan"
// #define PASSWORD "dydelu"

//========================================================================================

#define MQTT_SERVER "192.168.1.15" // (Enter your WiFi or Ethernet IP)
#define MQTT_PORT 1883             // 1883

//========================================================================================

#define MQTT_SCREEN_PATH "/living/screen"

#define MQTT_LIGHT_BEDROOM "/bedroom/light"
#define MQTT_LIGHT_LIVING "/livingroom/light"
#define MQTT_LIGHT_KITCHEN "/kitchen/light"

#define MQTT_TEMPERATURE_LIVING "/sensor/living/temperature"
#define MQTT_PRESSURE_LIVING "/sensor/living/pressure"
#define MQTT_ALTITUDE_LIVING "/sensor/living/altitude"

#define MQTT_BUTTON_1 "/sensor/button1"
#define MQTT_BUTTON_2 "/sensor/button2"

//========================================================================================

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//========================================================================================

WiFiClient espClient;
PubSubClient mqtt(espClient);
Adafruit_BMP3XX bmp;
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//========================================================================================

void MQTTcallback(char *topic, byte *payload, unsigned int length)
{
  String topicString(topic);
  String value((char *)payload);
  value = value.substring(0, length);

  if (topicString == MQTT_LIGHT_BEDROOM)
  {
    Serial.println("command received : " + value);
    if (value == "#on")
    {
      digitalWrite(LED1, HIGH);
    }
    else if (value == "#off")
    {
      digitalWrite(LED1, LOW);
    }
  }
  else if (topicString == MQTT_LIGHT_KITCHEN)
  {
    Serial.println("command received : " + value);
    if (value == "#on")
    {
      digitalWrite(LED2, HIGH);
    }
    else if (value == "#off")
    {
      digitalWrite(LED2, LOW);
    }
  }
  else if (topicString == MQTT_LIGHT_LIVING)
  {
    Serial.println("command received : " + value);
    if (value == "#on")
    {
      digitalWrite(LED3, HIGH);
    }
    else if (value == "#off")
    {
      digitalWrite(LED3, LOW);
    }
  }
  else if (topicString == MQTT_SCREEN_PATH)
  {
    // DO SOMETHING
  }
}

void MQTTreconnect()
{
  // Loop until we're reconnected
  while (!mqtt.connected())
  {
    Serial.print("Attempting MQTT connection");
    // create a random client ID
    String clientId = "ESP32Client-";
    // Attempt to connect
    if (mqtt.connect(clientId.c_str()))
    {
      Serial.println("connected");

      mqtt.subscribe(MQTT_SCREEN_PATH);
      mqtt.subscribe(MQTT_LIGHT_LIVING);
      mqtt.subscribe(MQTT_LIGHT_KITCHEN);
      mqtt.subscribe(MQTT_LIGHT_BEDROOM);
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(mqtt.state());
      Serial.print("try again in 5 seconds");
      // Wit 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  //===========LED============
  pinMode(LED1, OUTPUT); // BEDROOM
  pinMode(LED2, OUTPUT); // KITCHEN
  pinMode(LED3, OUTPUT); // LIVING
  //=========================

  Serial.begin(115200);
  delay(10);

  //========BMP388===========
  while (!Serial)
    ;
  Serial.println("Adafruit BMP388 connected");
  if (!bmp.begin_I2C())
  { // hardware I2C mode, can pass in address & alt Wire
    Serial.println("Could not find a valid BMP388 sensor, check wiring!");
    while (1)
      ;
  }
  // Set up oversampling and filter initialization
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
  //=======================

  // connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to : ");
  Serial.print(SSID);

  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi network connected");
  Serial.println(WiFi.localIP());

  // connecting to a mqtt broker
  mqtt.setServer(MQTT_SERVER, MQTT_PORT);
  mqtt.setCallback(MQTTcallback);
}

void loop()
{
  if (!mqtt.connected())
  {
    MQTTreconnect();
  }
  mqtt.loop();

  if (!bmp.performReading())
  {
    Serial.println("Failed to perform reading :(");
    return;
  }

  PRESSION_CHAMBRE = (bmp.pressure / 100.0);
  ALTITUDE_CHAMBRE = bmp.readAltitude(SEALEVELPRESSURE_HPA);
  TEMPERATURE_CHAMBRE = bmp.temperature;

  mqtt.publish(MQTT_PRESSURE_LIVING, String(PRESSION_CHAMBRE).c_str());
  mqtt.publish(MQTT_ALTITUDE_LIVING, String(ALTITUDE_CHAMBRE).c_str());
  mqtt.publish(MQTT_TEMPERATURE_LIVING, String(TEMPERATURE_CHAMBRE).c_str());

  if (!isnan(PRESSION_CHAMBRE))
  {
    Serial.print("press hPa =");
    Serial.print(TEMPERATURE_CHAMBRE);
    Serial.print("\t\t");
  }
  else
  {
    Serial.println("Failed to read pressure");
  }

  if (!isnan(ALTITUDE_CHAMBRE))
  {
    Serial.print("Approx. Altitude =");
    Serial.print(ALTITUDE_CHAMBRE);
    Serial.print("\t\t");
  }
  else
  {
    Serial.println("Failed to read altitude");
  }

  if (!isnan(TEMPERATURE_CHAMBRE))
  {
    Serial.print("temp *C =");
    Serial.print(TEMPERATURE_CHAMBRE);
    Serial.print("\t\t");
  }
  else
  {
    Serial.println("Failed to read temperature");
  }
}