int IN1 = 2; /* basilikum */
int IN2 = 3; /* Thymian links */
int IN3 = 4; /* Tomate */
int IN4 = 5; /* Thymian rechts */

char label1[] = "Tomate";
char label2[] = "Basilikum";
char label3[] = "Thymian rechts";
char label4[] = "Thymian links";

int Pin1 = A0;
int Pin2 = A1;
int Pin3 = A2;
int Pin4 = A3;

float value1 = 0;
float value2 = 0;
float value3 = 0;
float value4 = 0;

float trs_1 = 550;
float trs_2 = 550;
float trs_3 = 550;
float trs_4 = 550;

float TRS_OVERFLOODED = 300;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin4, INPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);

  delay(500);
}

void loop() {

  int delay_duration = 10000;

  /* measurement */
  value1 = analogRead(Pin1);
  value2 = analogRead(Pin2);
  value3 = analogRead(Pin3);
  value4 = analogRead(Pin4);
  
  /* Emergency exit*/
  if (value1 < TRS_OVERFLOODED ||
    value2 < TRS_OVERFLOODED ||
    value3 < TRS_OVERFLOODED ||
    value4 < TRS_OVERFLOODED) {

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);

    /* Sleep 1,5 mins */
    Serial.println("Emergency mode. At least one plant is overflooded. ");
    delay_duration = 100000;
  } else {

    Serial.print(label1);
    Serial.print(": ");
    Serial.println(value1);
    if (value1 > trs_1) {
      delay_duration = 500;
      digitalWrite(IN3, LOW);
    } else {
      digitalWrite(IN3, HIGH);
    }

    Serial.print(label2);
    Serial.print(": ");
    Serial.println(value2);
    if (value2 > trs_2) {
      delay_duration = 500;
      digitalWrite(IN1, LOW);
    } else {
      digitalWrite(IN1, HIGH);
    }

    Serial.print(label3);
    Serial.print(": ");
    Serial.println(value3);
    if (value3 > trs_3) {
      delay_duration = 500;
      digitalWrite(IN4, LOW);
    } else {
      digitalWrite(IN4, HIGH);
    }

    Serial.print(label4);
    Serial.print(": ");
    Serial.println(value4);
    if (value4 > trs_4) {
      delay_duration = 500;
      digitalWrite(IN2, LOW);
    } else {
      digitalWrite(IN2, HIGH);
    }

  }
  delay(delay_duration);
}
