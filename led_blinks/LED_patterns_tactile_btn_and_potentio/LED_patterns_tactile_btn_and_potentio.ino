// this constant won't change:
const int  bttn_pin = 13;                                    // the pin that the pushbutton is attached to
const int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};                            // the pin that the LED is attached to
const int length = sizeof(pins)/sizeof(int);
const int pot_pin = A0;

// Variables will change:
int counter = 0;   // counter for the number of button presses
int bttn_state = 0;         // current state of the button
int last_bttn_state = 0;     // previous state of the button

int delay_time;                                          

bool check_state(){
    // compare the buttonState to its previous state
    if (bttn_state != last_bttn_state) {
        // if the state has changed, increment the counter
        if (bttn_state == HIGH) {
          // if the current state is HIGH then the button went from off to on:
          counter++;
          last_bttn_state = bttn_state;
          Serial.println("on");
          Serial.print("number of button pushes: ");
          Serial.println(counter);
          return true;
        } else {
          // if the current state is LOW then the button went from on to off:
          Serial.println("off");
        }
        // Delay a little bit to avoid bouncing
        delay(50);
        // save the current state as the last state, for next time through the loop
        last_bttn_state = bttn_state;
    }

}

void pattern1(){
    for(int pin = 0; pin<length; pin++){
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);
        digitalWrite(pins[pin], 1);
        
        if(check_state() == true){                          //check if the bttn is clicked
            break;                                          // if true then break the loop
        } delay(delay_time);

        digitalWrite(pins[pin], 0);
    }
}


void pattern2(){
    for(int pin=0; pin < length; pin++){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);                         //turn on the current pin
        if(check_state() == true){
            break;
        }
        delay(delay_time);
        digitalWrite(pins[pin], 0);
    }

    for(int pin=length-1; pin > 0; pin--){                  //linearly scan through the pins 
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);                         //turn off the current pin
        if(check_state() == true){
            break;
        }
        delay(delay_time);                                         //then wait for 300ms
        digitalWrite(pins[pin], 0);
    }

}

void pattern3(){
    for(int pin=0; pin < length; pin++){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        if(pin % 2 == 0){
            digitalWrite(pins[pin], 1);                         //turn on the current pin
            if(check_state() == true){
                break;
            }
            delay(delay_time);
            digitalWrite(pins[pin], 0);

        }
        digitalWrite(pins[pin], 0);
        if(check_state() == true){
            break;
        }
        delay(delay_time);
    }
    for(int pin=length-1; pin >= 0; pin--){                  //linearly scan through the pins 
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        if(pin % 2 == 0){
            digitalWrite(pins[pin], 1);                         //turn on the current pin
            if(check_state() == true){
                break;
            }
            delay(delay_time);
            digitalWrite(pins[pin], 0);

        }
        digitalWrite(pins[pin], 0);
        if(check_state() == true){
            break;
        }
        delay(delay_time);
    }

}

void pattern4(){
    int pin, pinn;
    int mid = length/2;
    for(pin=0, pinn=length-1; (pin <= mid && pinn >= mid); pin++, pinn--){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);
        digitalWrite(pins[pinn], 1);

        if(check_state() == true){
            break;
        } delay(delay_time);

        digitalWrite(pins[pin], 0);
        digitalWrite(pins[pinn], 0);

        if(check_state() == true){
            break;
        } delay(delay_time);
    }
    for(pin=mid-1, pinn=mid+1; (pin>0 && pinn<length-1); pin--, pinn++){
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);
        digitalWrite(pins[pinn], 1);

        if(check_state() == true){
            break;
        } delay(delay_time);

        digitalWrite(pins[pin], 0);
        digitalWrite(pins[pinn], 0);

        if(check_state() == true){
            break;
        } delay(delay_time);

    }
    

}


void pattern5(){
    for(int pin=0; pin < length; pin++){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);                         //turn on the current pin
        if(check_state() == true){
            break;
        }
        delay(delay_time);
    }
    for(int pin=0; pin < length; pin++){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 0);                         //turn on the current pin
        if(check_state() == true){
            break;
        }
        delay(delay_time);
        
    }

}


void pattern6(){
    for(int pin=0; pin < length; pin++){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);                         //turn on the current pin
        if(check_state() == true){
            break;
        }
        delay(delay_time);
    }
    for(int pin=length-1; pin >= 0; pin--){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 0);                         //turn on the current pin
        if(check_state() == true){
            break;
        }
        delay(delay_time);
        
    }

}

void pattern7(){
    int pin, count;
    for(pin = 0, count = 0; pin <= length-1; pin++, ++count){
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);                         //turn on the current pin

        if(check_state() == true){
            break;
        } delay(delay_time);



        if(count == 2){
            if(pin == length-1){
                digitalWrite(pins[pin-2], 0);
                delay(delay_time);
                digitalWrite(pins[pin - 1], 0);
                if(check_state() == true){
                    break;
                } delay(delay_time);

                digitalWrite(pins[pin], 0);
                continue;
            }
            digitalWrite(pins[pin], 0);
            digitalWrite(pins[pin-1], 1);
            digitalWrite(pins[pin-2], 1);
            digitalWrite(pins[pin+1], 1);
            if(check_state() == true){
                break;
            } delay(delay_time);

            digitalWrite(pins[pin-2], 0);
            count -= 1;
            continue;
        }

        digitalWrite(pins[pin], 0);                         //turn on the current pin
    }

    for(pin = length-1, count =  0; pin >= 0; pin--, count++){
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);                         //turn on the current pin

        if(check_state() == true){
            break;
        } delay(delay_time);


        if (count == 2){
            digitalWrite(pins[pin+1], 0);
            digitalWrite(pins[pin-1], 1);
            if(check_state() == true){
                break;
            } delay(delay_time);

            digitalWrite(pins[pin+1], 1);
            count -= 1;
        }
        if(pin == 0){
            digitalWrite(pins[pin], 0);
            delay(delay_time);
            digitalWrite(pins[pin], 1);
        }

    }
    for(pin =  length-1; pin >= 0; pin--){
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        if(check_state() == true){
            break;
        } delay(delay_time);

        digitalWrite(pins[pin], 0);
        delay(delay_time);
    }
}

void pattern8(){
    int pin, pinn, count;

    for(pin = 0, count = 0; pin <= length-1; pin++, count++){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);                         //turn on the current pin
        if(check_state() == true){
            break;
        }
        delay(delay_time);
          

        if(count == 2){
            digitalWrite(pins[pin-2], 0);
            count -= 1;
            delay(delay_time);

            if(pin == length-1){
                digitalWrite(pins[length-2], 0);
                delay(delay_time);
                digitalWrite(pins[length-1], 0);
                delay(delay_time);
            }
            if(check_state() == true){
                break;
            }
        }
    }
    
    for(pinn = length-1, count = 0; pinn >= 0; pinn--, count++){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pinn], 1);                         //turn on the current pin
        if(check_state() == true){
            break;
        }
        delay(delay_time);
          

        if(count == 2){
            digitalWrite(pins[pinn+2], 0);
            count -= 1;
            delay(delay_time);

            if(pinn == 0){
                delay(delay_time);
                digitalWrite(pins[1], 0);
                delay(delay_time);
                digitalWrite(pins[0], 0);
                delay(delay_time);
            }
            if(check_state() == true){
                break;
            }
        }
    }
}
  

void pattern9(){
    int pin, pinn;
    int mid = length/2;
    for(pin=0, pinn=length-1; (pin <= mid && pinn >= mid); pin++, pinn--){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);
        digitalWrite(pins[pinn], 1);
        if(check_state() == true){
            break;
        } delay(delay_time);

        digitalWrite(pins[pin], 0);
        digitalWrite(pins[pinn], 0);
        if(check_state() == true){
            break;
        } delay(delay_time);
    }

}
void pattern10(){
    int pin, pinn;
    int mid = length/2;
    for(pin=0, pinn=length-1; (pin <= mid && pinn >= mid); pin++, pinn--){                    //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
      	delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 1);
        digitalWrite(pins[pinn], 1);
        if(check_state() == true){
            break;
        } delay(delay_time);

        digitalWrite(pins[pin], 0);
        digitalWrite(pins[pinn], 0);

        if(check_state() == true){
            break;
        } delay(delay_time);
    }

    for(pin=mid, pinn=mid; (pin >= 0 && pinn <= length-1); pin--, pinn++){          //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);

       digitalWrite(pins[pin], 1);
       digitalWrite(pins[pinn], 1);

        if(check_state() == true){
            break;
        } delay(delay_time);
    }                           
    for(pin=mid, pinn=mid; (pin >= 0 && pinn <= length-1); pin--, pinn++){          //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);

       digitalWrite(pins[pin], 0);
       digitalWrite(pins[pinn], 0);

        if(check_state() == true){
            break;
        } delay(delay_time);
    }                           
}


void pattern11(){
    int pin, pinn;
    int mid = length/2;
    for(pin = 0, pinn= length-1; (pin <= mid && pinn >= mid); pin++, pinn--){          //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);

       digitalWrite(pins[pin], 1);
       digitalWrite(pins[pinn], 1);
        if(check_state() == true){
            break;
        } delay(delay_time);
    }                           
    for(pin = 0, pinn= length-1; (pin <= mid && pinn >= mid); pin++, pinn--){          //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
       digitalWrite(pins[pin], 0);
       digitalWrite(pins[pinn], 0);

        if(check_state() == true){
            break;
        } delay(delay_time);
    }                           
}


void pattern12(){
    int pin, pinn, count=0;
    int mid = length/2;

    for(int pin=0; pin<length; pin++){
        digitalWrite(pins[pin], 1);
    }delay(200);

    for(pin = 0, pinn= length-1; (pin <= mid && pinn >= mid); pin++, pinn--){          //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 0);
        digitalWrite(pins[pinn], 0);
        if(check_state() == true){
            break;
        } delay(delay_time);
    }                           
    for(int pin=0; pin<length; pin++){
        digitalWrite(pins[pin], 1);
    }delay(delay_time);

    for(pin=mid, pinn=mid; (pin >= 0 && pinn <= length-1); pin--, pinn++){          //linearly scan through the pins
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);

        digitalWrite(pins[pin], 0);
        digitalWrite(pins[pinn], 0);
        if(check_state() == true){
            break;
        } delay(delay_time);
    }                           
}


void pattern13(){
    int pin, pinn;
    int mid = length/2;
    int count; 
    for( count = 0; count <= mid; count++){
        for(pin=0, pinn=length-1; (pin <= mid-count && pinn >= mid+count); pin++, pinn--){                    //linearly scan through the pins
            bttn_state = digitalRead(bttn_pin);
            delay_time = analogRead(pot_pin);

            digitalWrite(pins[pin], 1);
            digitalWrite(pins[pinn], 1);

            if(check_state() == true){
                break;
            }delay(delay_time);

            digitalWrite(pins[pin], 0);
            digitalWrite(pins[pinn], 0);

            if(pin == mid-count && pinn == mid+count){
                digitalWrite(pins[pin], 1);
                digitalWrite(pins[pinn], 1);

                if(check_state() == true){
                    break;
                }delay(delay_time);

            }
            
            if(check_state() == true){
                break;
            }
            delay(delay_time);
        }

    }
    for(int pin=0; pin<length; pin++){
        digitalWrite(pins[pin], 0);
    }
    delay(delay_time);

}

void pattern14(){
    int pin, count;
    int k = length-1;
    for( count = 0; count <= k; count++){
        for(pin = 0; pin <= k-count; pin ++){                    //linearly scan through the pins
            bttn_state = digitalRead(bttn_pin);
            delay_time = analogRead(pot_pin);

            digitalWrite(pins[pin], 1);
            if(check_state() == true){
                break;
            } delay(delay_time);

            
            digitalWrite(pins[pin], 0);

            if(pin == k-count){
                digitalWrite(pins[pin], 1);
            }
            
        }

    }
}

void pattern15(){
    int pin, count;
    int k = length-1;

    for(int pin=0; pin<=k; pin++){
        digitalWrite(pins[pin], 1);
    }delay(100);

    for(count = k; count >= 0; count--){
        for(pin = count; pin <= k; pin++){
            bttn_state = digitalRead(bttn_pin);
            delay_time = analogRead(pot_pin);

            digitalWrite(pins[pin], 1);
            if(check_state() == true){
                break;
            } delay(delay_time);

            digitalWrite(pins[pin], 0);

        }

    }

}

void pattern16(){
    for(int pin = 0; pin <= length-1; pin ++){
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);

        if (pin % 2 == 0){
            digitalWrite(pins[pin], 1);

            if(check_state() == true){
                break;
            } 
        }
    }delay(delay_time);

    for(int pin = 0; pin <= length-1; pin ++){
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);
        if (pin % 2 == 0){
            digitalWrite(pins[pin], 0);

            if(check_state() == true){
                break;
            } 
        }delay(delay_time);
    }

    for(int pin = 0; pin <= length-1; pin ++){
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);

        if (pin % 2 == 1){
            digitalWrite(pins[pin], 1);

            if(check_state() == true){
                break;
            }
        } delay(delay_time);
    }delay(delay_time);

    for(int pin = 0; pin <= length-1; pin ++){
        bttn_state = digitalRead(bttn_pin);
        delay_time = analogRead(pot_pin);

        if (pin % 2 == 1){
            digitalWrite(pins[pin], 0);

            if(check_state() == true){
                break;
            } 
        } delay(delay_time);
    }delay(100);

}


void setup() {
  // initialize the button pin as a input:
  pinMode(bttn_pin, INPUT);

  // initialize the LED as an output:
    for(int pin=0; pin < length; pin++){
     	pinMode(pins[pin], OUTPUT);
    }

  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  bttn_state = digitalRead(bttn_pin);

  check_state();
  

    if (counter == 1) {
        pattern1();
    }
    else if(counter == 2) {
        pattern2();
    }
    else if(counter == 3){
        pattern3();
    }
    else if(counter == 4){
        pattern4();
    }
    else if(counter == 5){
        pattern5();
    }
    else if(counter == 6){
        pattern6();
    }
    else if(counter == 7){
        pattern7();
    }
    else if(counter == 8){
        pattern8();
    }
    else if(counter == 9){
        pattern9();
    }
    else if(counter == 10){
        pattern10();
    }
    else if(counter == 11){
        pattern11();
    }
    else if(counter == 12){
        pattern12();
    }
    else if(counter  == 13){
        pattern13();
    }
    else if(counter  == 14){
        pattern14();
    }
    else if(counter  == 15){
        pattern15();
    }
    else if(counter  == 16){
        pattern16();
    }
    else if(counter  == 17){
        counter = 1;
    }
    else{
        for(int pin = 0; pin < length-1; pin++){
            digitalWrite(pins[pin], 0);
        }
    }

}
