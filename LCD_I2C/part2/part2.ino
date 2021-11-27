#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define sensor 2
#define DHTTYPE DHT11
DHT dht(sensor, DHTTYPE);

const unsigned long event_interval = 2000;
unsigned long prev_time = 0;


LiquidCrystal_I2C lcd(0x27, 16, 2);


void displayTemp(float tempc, float humid){
    lcd.setCursor(0,0);
    lcd.print("Temp in C = ");
    lcd.println(tempc);
    lcd.setCursor(0,1);
    lcd.print("Humidity = ");
    lcd.println(humid);
}

void setup() {
    Serial.begin(9600);
    pinMode(sensor, INPUT);

    dht.begin();

    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("   Activity 3 ");
    lcd.setCursor(0, 1);
    lcd.print("  DHT11 Sensor");
}

void loop() {
    unsigned long curr_time = millis();

    if(curr_time - prev_time >= event_interval){

        float temp = dht.readTemperature();;
        float humid = dht.readHumidity();
        

        displayTemp(temp, humid);


        prev_time = curr_time;
    }
}
