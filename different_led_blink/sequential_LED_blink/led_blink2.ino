const int pins[] = {6, 7, 8};                       //initialize array of pins
const int length = sizeof(pins)/sizeof(int);        //get the length of the array

void setup() {
    for(int pin=0; pin < length; pin++){            //set all pins pinMODE to OUTPUT
        pinMode(pins[pin], OUTPUT);
    }
}

void loop() {
    for(int pin=0; pin < length; pin++){            //linearly scan through the pins
        digitalWrite(pins[pin], 1);                 //turn on the current pin
        delay(200);                                 //then wait for 300ms
    }

    for(int pin=0; pin < length; pin++){            //linearly scan through the pins 
        digitalWrite(pins[pin], 0);                 //turn off the current pin
        delay(300);                                 //then wait for 300ms
    }

}
