int ledPin = 2;
int speedDelay = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Serial.println("Input 1,2,3:");
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();

    // เคลียร์ตัวอักษรที่เหลือ (เช่น \n, \r) ออกจาก buffer
    while (Serial.available() > 0) {
      Serial.read();
    }

    if (value == 1) {
      speedDelay = 1000;
      Serial.println("Blink every 2s");
    } else if (value == 2) {
      speedDelay = 500;
      Serial.println("Blink every 1s");
    } else if (value == 3) {
      speedDelay = 250;
      Serial.println("Blink every 0.5s");
    } else {
      speedDelay = 0;
      Serial.println("Wrong Input");
    }
  }

  if (speedDelay > 0) {
    digitalWrite(ledPin, HIGH);
    delay(speedDelay);
    digitalWrite(ledPin, LOW);
    delay(speedDelay);
  }
}