int redPin = 2;
int greenPin = 3;
int bluePin = 4;

String command = "";

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  // pinMode(greenPin, OUTPUT);
  // pinMode(bluePin, OUTPUT);

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
    else if (command == "BLUE") {
      allOff();
      digitalWrite(bluePin, HIGH);
      Serial.println("Blue ON");
    } 
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
  // digitalWrite(greenPin, LOW);
  // digitalWrite(bluePin, LOW);
}