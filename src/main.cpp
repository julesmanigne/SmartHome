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
#include "DHT.h"

//========================================================================================

#define LED1 19
#define LED2 18
#define LED3 15
#define DHTPIN 17 // what digital pin we're connected to
#define DHTTYPE DHT11

// float TEMPERATURE_CHAMBRE = 0.0;
// float PRESSION_CHAMBRE = 0.0;
// float ALTITUDE_CHAMBRE = 0.0;
// float HUMIDITE_CHAMBRE = 0.0;

float TEMPERATURE_SALON = 0.0;
float PRESSION_SALON = 0.0;
float ALTITUDE_SALON = 0.0;
float HUMIDITE_SALON = 0.0;
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
#define MQTT_HUMIDITE_LIVING "/sensor/living/humidity"

// #define MQTT_TEMPERATURE_BEDROOM "/sensor/bedroom/temperature"
// c#define MQTT_PRESSURE_BEDROOM "/sensor/bedroom/pressure"
// #define MQTT_ALTITUDE_BEDROOM "/sensor/bedroom/altitude"
// #define MQTT_HUMIDITE_BEDROOM "/sensor/bedroom/humidite"

//========================================================================================

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//========================================================================================

WiFiClient espClient;
PubSubClient mqtt(espClient);
Adafruit_BMP3XX bmpL;
// Adafruit_BMP3XX bmpB;
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dhtLiving(DHTPIN, DHTTYPE);

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

  Serial.begin(115200);
  delay(10);

  //===========LED============
  pinMode(LED1, OUTPUT); // BEDROOM
  pinMode(LED2, OUTPUT); // KITCHEN
  pinMode(LED3, OUTPUT); // LIVING
  //=========================

  //===========DHT===========
  Serial.println("DHT11 test!");
  dhtLiving.begin();
  //========================

  //========BMP388===========
  while (!Serial)
    ;
  Serial.println("Adafruit BMP388 connected");
  if (!bmpL.begin_I2C())
  { // hardware I2C mode, can pass in address & alt Wire
    Serial.println("Could not find a valid BMP388 sensor, check wiring!");
    while (1)
      ;
  }
  // Set up oversampling and filter initialization
  bmpL.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmpL.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmpL.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmpL.setOutputDataRate(BMP3_ODR_50_HZ);
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

  if (!bmpL.performReading())
  {
    Serial.println("Failed to perform reading :(");
    return;
  }

  // PRESSION_CHAMBRE = (bmpB.pressure / 100.0);
  // ALTITUDE_CHAMBRE = bmpB.readAltitude(SEALEVELPRESSURE_HPA);
  // TEMPERATURE_CHAMBRE = bmpB.temperature;
  // HUMIDITE_CHAMBRE = ;

  PRESSION_SALON = (bmpL.pressure / 100.0);
  ALTITUDE_SALON = bmpL.readAltitude(SEALEVELPRESSURE_HPA);
  TEMPERATURE_SALON = bmpL.temperature;
  HUMIDITE_SALON = dhtLiving.readHumidity();

  // mqtt.publish(MQTT_PRESSURE_BEDROOM, String(PRESSION_CHAMBRE).c_str());
  // mqtt.publish(MQTT_ALTITUDE_BEDROOM, String(ALTITUDE_CHAMBRE).c_str());
  // mqtt.publish(MQTT_TEMPERATURE_BEDROOM, String(TEMPERATURE_CHAMBRE).c_str());
  // mqtt.publish(MQTT_HUMIDITE_BEDROOM, String(HUMIDITE_CHAMBRE).c_str());

  mqtt.publish(MQTT_PRESSURE_LIVING, String(PRESSION_SALON).c_str());
  mqtt.publish(MQTT_ALTITUDE_LIVING, String(ALTITUDE_SALON).c_str());
  mqtt.publish(MQTT_TEMPERATURE_LIVING, String(TEMPERATURE_SALON).c_str());
  mqtt.publish(MQTT_HUMIDITE_LIVING, String(HUMIDITE_SALON).c_str());

  if (!isnan(PRESSION_SALON))
  {
    Serial.print("press hPa =");
    Serial.print(PRESSION_SALON);
    Serial.print("\t\t");
  }
  else
  {
    Serial.println("Failed to read pressure");
  }

  if (!isnan(ALTITUDE_SALON))
  {
    Serial.print("Approx. Altitude =");
    Serial.print(ALTITUDE_SALON);
    Serial.print("\t\t");
  }
  else
  {
    Serial.println("Failed to read altitude");
  }

  if (!isnan(TEMPERATURE_SALON))
  {
    Serial.print("temp *C =");
    Serial.print(TEMPERATURE_SALON);
    Serial.print("\t\t");
  }
  else
  {
    Serial.println("Failed to read temperature");
  }

  if (!isnan(HUMIDITE_SALON))
  {
    Serial.print("Humidity: ");
    Serial.print(HUMIDITE_SALON);
    Serial.print(" %\t");
  }
  else
  {
    Serial.println("Failed to read temperature");
  }
}