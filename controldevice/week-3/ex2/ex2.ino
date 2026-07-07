int ledPin = 2;
int speedDelay = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Serial.println("Input 1,2,3:");
  // put your setup code here, to run once:

}

void loop() {
  if(Serial.available()>0){
    int value = Serial.parseInt();
    if(value == 1){
      speedDelay = 2000;
      // Serial.println("Slow Blink as 2000ms");
    }else if(value == 2){
      speedDelay = 1000;
      // Serial.println("Slow Blink as 1000ms");
    }else if(value == 3){
      speedDelay = 500;
      // Serial.println("Slow Blink as 500ms");
    }else{
      speedDelay = 0;
      Serial.println("Wrong Input");
    }

  }
  // put your main code here, to run repeatedly:
  if(speedDelay>0){
    digitalWrite(ledPin, HIGH);
    delay(speedDelay);
    digitalWrite(ledPin, LOW);
    delay(speedDelay);
  }
  
  
}
