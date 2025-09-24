#define LED_PIN 7
#define Period 0.1 //ms

int set_period(float period) {
  return (period * 1000);
}

float set_duty(float duty) {
  return duty/100;
}

void analog_LED_write(float duty, float period) {
  digitalWrite(LED_PIN, 0);
  delayMicroseconds(period * duty);
  digitalWrite(LED_PIN, 1);
  delayMicroseconds(period * (1 - duty));
}

void Fade(int period) {
  for (float i = 0; i < 500000/period; i++) {
      analog_LED_write(set_duty(100*(i/(500000/period))), period);
  }
  for (float i = 500000/period; i >= 0; i--) {
      analog_LED_write(set_duty(100*(i/(500000/period))), period);
  }
}
  
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  Fade(set_period(Period));
}
