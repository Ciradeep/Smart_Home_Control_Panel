int pin = 9;       // Fan or PWM output
int buzz = 2;      // Buzzer
int red = 3;
int blue = 5;
int green = 11;

int pot = A0;
int temp = A1;
int speed;
float readtemp;
float newtemp;
float cal;
float scale_f = 0.5;

int r;
int user;
int pass = 1234;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(pin, OUTPUT); // For fan or PWM LED
  Serial.begin(9600);
}

void loop() {
  Serial.println("Enter the correct password to enter the house:");
  while (Serial.available() == 0);

  user = Serial.parseInt();

  if (user == pass) {
    Serial.println(" Access Granted!");

    // Access indicator
    analogWrite(blue, 200);
    analogWrite(green, 200);
    delay(3000);
    analogWrite(blue, 0);
    analogWrite(green, 0);

    // Fan speed control
    speed = analogRead(pot);
    r = map(speed, 0, 1023, 0, 255);
    analogWrite(pin, r);  // Control fan or motor safely

    // Temperature reading
    readtemp = analogRead(temp);
    cal = readtemp * (5.0 / 1023.0);
    newtemp = (cal - scale_f) * 100.0;

    Serial.print(" Current Temperature: ");
    Serial.print(newtemp);
    Serial.println(" °C");

    // Temp-based color & alert
    if (newtemp < 25) {
      Serial.println(" Temperature is low. (Blue LED ON)");
      analogWrite(blue, 255);
      delay(4000);
      analogWrite(blue, 0);
    } else if (newtemp <= 35) {
      Serial.println(" Temperature is normal. (Green LED ON)");
      analogWrite(green, 255);
      delay(4000);
      analogWrite(green, 0);
    } else {
      Serial.println(" Temperature is too high! Alert! (Red LED & Buzzer ON)");
      analogWrite(red, 255);
      digitalWrite(buzz, HIGH);
      delay(3000);
      analogWrite(red, 0);
      digitalWrite(buzz, LOW);
    }

    // Turn off fan after some time (safety)
    delay(5000);
    analogWrite(pin, 0);
    Serial.println(" Fan turned off to save power.");

  } else {
    // Wrong password response
    Serial.println(" Wrong password. Try again.");
    analogWrite(red, 255);
    digitalWrite(buzz, HIGH);
    delay(1500);
    analogWrite(red, 0);
    digitalWrite(buzz, LOW);
  }

  delay(2000);  // Brief pause before restart
}
