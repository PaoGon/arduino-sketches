const int segments[] = {3, 4, 5, 6, 7, 8, 9};
const int digits[] {13, 12, 11, 10};
const int btns[] = {14, 15, 16, 17};
const int pins_len = sizeof(segments)/sizeof(int);
const int dig_len = sizeof(digits)/sizeof(int);
const int btns_len = sizeof(btns)/sizeof(int);

const int relay_pin = 2; 

int add_state = 0;
int sub_state = 0;
int start_state = 0;
int reset_state = 0;
int counter = 9998;


void on_segments(int digit) { 
    for(int segment = 0; segment <= pins_len-1; segment++){
        digitalWrite(segments[segment],0); 
    }
 //turning on segment a 
    if(digit!=1 && digit != 4){
        digitalWrite(segments[0],1); 
    } 
  
 //turning on segment b 
    if(digit != 5 && digit != 6) {
        digitalWrite(segments[1],1); 
    }

 //turning on segment c 
    if(digit !=2){
        digitalWrite(segments[2],1); 
    } 

 //turning on segment d 
    if(digit != 1 && digit !=4 && digit !=7) {
        digitalWrite(segments[3],1); 
    }

 //turning on segment e 
    if(digit == 2 || digit ==6 || digit == 8 || digit==0){
        digitalWrite(segments[4],1); 
    }

 //turning on segment f 
    if(digit != 1 && digit !=2 && digit!=3 && digit !=7){
        digitalWrite(segments[5],1); 
    }

 //turning on segment g 
    if (digit!=0 && digit!=1 && digit !=7){
        digitalWrite(segments[6],1); 
    }
  
} 
void x(int num){
    for(int i = 0; i <= dig_len-1; i++){
        if(i == num){
            digitalWrite(digits[i], 0);
        }
        else{
            digitalWrite(digits[i], 1);
        }
    }

}

void display_num(int num, int time){
    String test = String(num);
    int k = test.length();
    for(int secs = 0; secs <= time/20; secs++){
        if(k == 1){
            x(0);
            on_segments(num);
            delay(10);
        }
        else if(k == 2){
            for(int digit = 0; digit < k; digit++){
                x(digit);
                if(digit == 0){
                    on_segments(num%10);
                }
                else{
                    on_segments(num/10);
                }
                delay(5);
            }
        }
        else if(k == 3){
            for(int digit = 0; digit < k; digit++){
                x(digit);
                if(digit == 0){
                    on_segments(num%10);
                }
                else if(digit == 1){
                    on_segments((num%100)/10);                
                }
                else{
                    on_segments(num/100);
                }
                delay(3);
                
            }
        }
        else if(k == 4){
            for(int digit = 0; digit < k; digit++){
                x(digit);
                if(digit == 0){
                    on_segments(num%10);
                }
                else if(digit == 1){
                    on_segments((num%100)/10);
                }
                else if(digit == 2){
                    on_segments((num%1000)/100);
                }
                else{
                    on_segments(num/1000);
                }
                delay(2);
            }
        }
    }
}

void start(){
    while(counter >= 0){
        display_num(counter, 1200);
        counter--;
    }
    digitalWrite(relay_pin, 1);
    delay(1000);
    digitalWrite(relay_pin, 0);
    delay(1000);
    counter += 9998;
}

void setup() {
    for(int pin = 0; pin < pins_len; pin++ ){
        pinMode(segments[pin], OUTPUT);
    }
    for(int digit = 0; digit < dig_len; digit++){
        pinMode(digits[digit], OUTPUT);
    }
    for(int btn = 0; btn < btns_len; btn++){
        pinMode(btns[btn], INPUT);
    }
    pinMode(relay_pin, OUTPUT);
    /*pinMode(bzz_pin, OUTPUT);*/
    
}

void loop() {
    add_state = digitalRead(btns[0]);    // read the vlaue of the digital pin assigned
    sub_state = digitalRead(btns[1]);    // read the vlaue of the digital pin assigned
    start_state = digitalRead(btns[2]);
    reset_state = digitalRead(btns[3]);

    display_num(counter, 1200);

    if(add_state == 1){
        if(counter == 9999){
            counter = 0;
        }
        else{
            counter++;
        }
    }
    if(sub_state == 1){
        if(counter == 0){
            counter = 9999;
        }
        else{
            counter--;
        }
    }
    if(start_state == 1){
        start();
    }
    if(reset_state == 1){
        counter = 0;
    }
}
