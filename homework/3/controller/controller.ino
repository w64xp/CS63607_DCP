int redPin = 2;
int greenPin = 2;
int bluePin = 2;

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

      // ติดค้างจนกว่าจะมีคำสั่งใหม่
      while (Serial.available() == 0);
    }

    else if (command == "GREEN") {
      Serial.println("Green Blink");

      while (Serial.available() == 0) {

        allOff();

        // กระพริบ 2 ครั้ง
        for (int i = 0; i < 2; i++) {
          digitalWrite(greenPin, HIGH);
          delay(150);
          digitalWrite(greenPin, LOW);
          delay(150);
        }

        // ดับ 5 วินาที
        delay(5000);
      }
    }

    else if (command == "BLUE") {
      Serial.println("Blue Blink");

      while (Serial.available() == 0) {

        allOff();

        // กระพริบ 3 ครั้ง
        for (int i = 0; i < 3; i++) {
          digitalWrite(bluePin, HIGH);
          delay(150);
          digitalWrite(bluePin, LOW);
          delay(150);
        }

        // ดับ 5 วินาที
        delay(5000);
      }
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
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}