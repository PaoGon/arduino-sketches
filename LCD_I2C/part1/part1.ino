#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int sensor = A0;
const int iteration = 100;

const unsigned long event_interval = 1000;
unsigned long prev_time = 0;


LiquidCrystal_I2C lcd(0x27, 16, 2);

float calc_celsius(){
    int temp_val = analogRead(sensor);
    float temp = (temp_val*5.0)/10;
    return temp;
}

void displayTemp(float tempc, float tempf){
    lcd.setCursor(0,0);
    lcd.print("Temp in C = ");
    lcd.println(tempc);
    lcd.setCursor(0,1);
    lcd.print("Temp in F = ");
    lcd.println(tempf);
}

void setup() {
    Serial.begin(9600);
    pinMode(sensor, INPUT);

    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("   Activity 3 ");
    lcd.setCursor(0, 1);
    lcd.print("  LM35 Sensor");
}

void loop() {
    unsigned long curr_time = millis();

    if(curr_time - prev_time >= event_interval){

        /*float avg_temp = 0;*/
        float avg_temp = calc_celsius();

        /*for(int i =0; i < iteration; i++){*/
            /*float temp  = calc_celsius();*/
            /*avg_temp += temp;*/
        /*}*/
        /*Serial.print("total: ");*/
        /*Serial.println(avg_temp);*/
        /*avg_temp /= iteration;*/

        float tempF = (avg_temp * 9/5) + 32;
        
        Serial.println(avg_temp);

        displayTemp(avg_temp, tempF);


        prev_time = curr_time;
    }
}

