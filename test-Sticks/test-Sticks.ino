const int links = A0;
const int rechts = A1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int stickl = analogRead(links);
int stickr = analogRead(rechts)+1024;

Serial.println(stickl);
Serial.println(stickr);
delay(2000);

}
