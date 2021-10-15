const int pins[] = {2, 3 , 4, 5, 6, 7, 8, 9};           //define array of pins
const int pot_pin = A0;                                 //define potentiometer pin
const int length = sizeof(pins)/sizeof(int);            //get the length of the array

void setup() {
    for(int pin=0; pin < length; pin++){                //set all pins pinMODE to OUTPUT
        pinMode(pins[pin], OUTPUT);
    }
}

void loop() {
    int delayTime = analogRead(pot_pin);                //get the value of the potetiometer and store it to a variable

    for(int pin=0; pin < length; pin++){                //linearly scan through the pins
        digitalWrite(pins[pin], 1);                     //turn on the current pin
        delay(delayTime);                               //then wait for the value of delayTime
    }

    for(int pin = length-1; pin >= 0; pin--){           //linearly scan through the pins 
        digitalWrite(pins[pin], 0);                     //turn off the current pin
        delay(delayTime);                               //then wait for the value of delayTime
    }            
}
