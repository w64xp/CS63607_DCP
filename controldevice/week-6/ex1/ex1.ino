int redPin = 15;
int greenPin = 18;
int bluePin = 22;

String command = "";

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  allOff();
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "RED") {
      allOff();
      digitalWrite(redPin, HIGH);
      Serial.println("Red ON");
    } 
    else if (command == "GREEN") {
      allOff();
      digitalWrite(greenPin, HIGH);
      Serial.println("Green ON");
    } 
    else if (command == "YELLOW") {
      allOff();
      digitalWrite(bluePin, HIGH);
      Serial.println("Blue ON");
    } 
    // else if (command == "YELLOW") {
    //   while (Serial.available() == 0) {

    //     allOff();
    //     // กระพริบ 2 ครั้ง
    //     for (int i = 0; i < 2; i++) {
    //       digitalWrite(redPin, HIGH);
    //       digitalWrite(greenPin, HIGH);
    //       digitalWrite(bluePin, HIGH);
    //       delay(150);
    //       digitalWrite(redPin, LOW);
    //       digitalWrite(greenPin, LOW);
    //       digitalWrite(bluePin, LOW);
    //       delay(150);
    //     }
        // ดับ 5 วินาที
        // delay(150);
    //   }
    // } 
    else if (command == "OFF") {
      allOff();
      Serial.println("All OFF");
    } 
    else {
      Serial.println("Unknown Command");
    }
  }
}

void allOff() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}