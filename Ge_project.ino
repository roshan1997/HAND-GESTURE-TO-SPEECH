//Demo code//
//Sign language to speech glove//
//By: Pratyush,Megashyam and Shashank//
//Full code would be available on the presentation day//

#define FLEXSENSORPIN0 A0 
#define FLEXSENSORPIN1 A1 
#define FLEXSENSORPIN2 A2 
#define FLEXSENSORPIN3 A3 
#define FLEXSENSORPIN4 A4
#define MAXSIZE 30
int buttonState = 0;
char arr [MAXSIZE];
int Rx = 0;
int Tx = 1; 
const int ledPin = 13;
float pinkyReading;
float ringReading;
float middleReading;
float indexReading;
float thumbReading;
void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(ledPin, OUTPUT); 
  pinMode(Rx,INPUT);
  pinMode(Tx,OUTPUT); 
}
float singleReading(int pin)
{
  float reading;
  reading = analogRead(pin);
  return reading;
}

void loop(){
 int i=0;
 if(Serial.available() > 0) {
    while(Serial.available() > 0) {
      arr[i] = Serial.read();
      i++;
    }
  }
  if(strcmp(arr,"read") == 0){
    Serial.println("h");
    arr[2] = 'w';
    
  }  //Serial.println(arr);
  if ((buttonState != digitalRead(2)) || (strcmp(arr,"read")== 0)){
  
  digitalWrite(ledPin, HIGH);  
  pinkyReading = singleReading(FLEXSENSORPIN1);
  ringReading = singleReading(FLEXSENSORPIN0);
  middleReading = singleReading(FLEXSENSORPIN2);
  indexReading = singleReading(FLEXSENSORPIN3);
  thumbReading = singleReading(FLEXSENSORPIN4);
  /*Serial.print("Single reading Pinky ");
  Serial.print("\t");  
  Serial.println(pinkyReading);
  //delay(100);
  Serial.print("Single reading Ring ");
  Serial.print("\t"); 
  Serial.println(ringReading);
  //delay(100);
  Serial.print("Single reading Middle ");
  Serial.print("\t");
  Serial.println(middleReading);
  //delay(100);
  Serial.print("Single reading Index ");
  Serial.print("\t"); 
  Serial.println(indexReading);
  //delay(100);
  Serial.print("Single reading Thumb ");
  Serial.print("\t"); 
  Serial.println(thumbReading);
  Serial.println("*********************************************************");
  //delay(100);*/
  delay(200);
  //Mapping alphabets and numbers with flex sensor values
 if((pinkyReading > 843) && (ringReading > 838) && ((middleReading > 770) && (middleReading < 805)) && ((indexReading > 735) && (indexReading < 770)))
 {
 Serial.println("h");
  arr[2] = 'w';
  
    
  }
  
  if(((pinkyReading > 750) && (pinkyReading < 800)) && (ringReading > 785) && ((middleReading > 780) && (middleReading < 838)) && ((indexReading > 750) && (indexReading < 850)))
 {
 Serial.println("i"); 
 arr[2] = 'w';   
  }
  }
  /*value = map(value, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin, value);          //Send PWM value to led
  delay(100);                          //Small delay
  */
}


