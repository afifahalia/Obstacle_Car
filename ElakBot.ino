
//pin
int pin_1 = 10;
int pin_2 = 11;
int pin_3 = 12;
int pin_4 = 13;

int merah = 6;
int hijau = 7;

int echo_pin = 2;
int trig_pin = 3;

long duration;
int distance;

void setup() {
 
  pinMode(pin_1, OUTPUT);
  pinMode(pin_2, OUTPUT);
  pinMode(pin_3, OUTPUT);
  pinMode(pin_4, OUTPUT);
  pinMode(merah, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(trig_pin, LOW);        // to clear trig pin condition
  delay(1000);
}

void loop() {

  readSensor();
  
  if (distance < 30){
    digitalWrite(merah, HIGH);
    digitalWrite(hijau, LOW);
    stopcar();
    reverse();
    changedirection();
  }
   else{
    forward();
   }
}

void readSensor(){
  digitalWrite(3, HIGH);
  delay(10);
  digitalWrite(3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(2, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.println(distance);
}
void stopcar(){
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, LOW);
  delay(100);
}
  

void reverse(){
  
  digitalWrite(pin_1, LOW);
  digitalWrite(pin_2, HIGH);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, HIGH);
  delay(100);
}

void forward(){
  digitalWrite(hijau, HIGH);
  digitalWrite(merah, LOW);
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, HIGH);
  digitalWrite(pin_4, LOW);
  delay(100);
  
}

void changedirection(){
  digitalWrite(pin_1, HIGH);
  digitalWrite(pin_2, LOW);
  digitalWrite(pin_3, LOW);
  digitalWrite(pin_4, LOW);
  delay(50); 
}
