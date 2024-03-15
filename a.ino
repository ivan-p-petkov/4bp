const int trigPin = 2; // Shared trig pin
const int echoPin1 = 3; // Echo pin for sensor 1
const int echoPin2 = 4; // Echo pin for sensor 2
const int echoPin3 = 5; // Echo pin for sensor 3
const int echoPin4 = 6; // Echo pin for sensor 4

int en1 = 8;
int en2 = 13;
int in1 = 9;
int in2 = 10;
int in21 = 11;
int in22 = 12;

float distance1, distance2, distance3, distance4;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in21, OUTPUT);
  pinMode(in22, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the pulse duration on echo pin of sensor 1
  long duration1 = pulseIn(echoPin1, HIGH);
  // Convert the pulse duration to distance in cm
  distance1 = duration1 * 0.034 / 2;

  // Trigger sensor 2
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the pulse duration on echo pin of sensor 2
  long duration2 = pulseIn(echoPin2, HIGH);
  // Convert the pulse duration to distance in cm
  distance2 = duration2 * 0.034 / 2;

  // Trigger sensor 3
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the pulse duration on echo pin of sensor 3
  long duration3 = pulseIn(echoPin3, HIGH);
  // Convert the pulse duration to distance in cm
  distance3 = duration3 * 0.034 / 2;

  // Trigger sensor 4
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the pulse duration on echo pin of sensor 4
  long duration4 = pulseIn(echoPin4, HIGH);

  // Convert the pulse duration to distance in cm
  distance4 = duration4 * 0.034 / 2;

  Serial.print("Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm, Sensor 2: ");
  Serial.print(distance2);
  Serial.print(" cm, Sensor 3: ");
  Serial.print(distance3);
  Serial.print(" cm, Sensor 4: ");
  Serial.print(distance4);
  Serial.println(" cm");

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(en1, 155);

  if(distance1 < 10 || distance2 < 10 || distance3 < 10 || distance4 < 10){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    Serial.println("tuksum");
    delay(3000);
  }
}
