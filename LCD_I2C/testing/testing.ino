const int sensor = A0;
const int iteration = 100;

const unsigned long event_interval = 2000;
unsigned long prev_time = 0;

float calc_celsius(){
    int temp_val = analogRead(sensor);
    float temp = (temp_val*5.0)/10;
    return temp;
}

void setup() {
    Serial.begin(9600);
    pinMode(sensor, INPUT);
}

void loop() {
    unsigned long curr_time = millis();

    if(curr_time - prev_time >= event_interval){
        float avg_temp = 0;

        for(int i =0; i < iteration; i++){
            float temp  = calc_celsius();
            Serial.print("temp: ");
            Serial.println(temp);
            avg_temp += temp;
        }
        Serial.print("total: ");
        Serial.println(avg_temp);
        avg_temp /= iteration;
        
        Serial.println(avg_temp);

        prev_time = curr_time;
    }
}
