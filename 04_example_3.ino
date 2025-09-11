#define PIN_LED 13
unsigned int count, toggle;

int toggle_state(int toggle){
  return toggle;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  Serial.println("Hello Wrold!");

  count=toggle=0;
  digitalWrite(PIN_LED,toggle);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(++count);
  toggle=toggle_state(count%2);
  digitalWrite(PIN_LED,toggle);
  delay(1000);
}
