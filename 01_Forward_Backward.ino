#define PWM1_PIN 5
#define PWM2_PIN 6
#define SHCP_PIN 2
#define EN_PIN 7
#define DATA_PIN 8
#define STCP_PIN 4

const int Forward = 92;
const int Backward = 163;

void setup() {
    pinMode(SHCP_PIN, OUTPUT);
    pinMode(EN_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(STCP_PIN, OUTPUT);
    pinMode(PWM1_PIN, OUTPUT);
    pinMode(PWM2_PIN, OUTPUT);
}

void loop() {
    Motor(Forward, 200);
    delay(2000);
    Motor(Backward, 200);
    delay(2000);
}

void Motor(int Dir, int Speed) {
    digitalWrite(EN_PIN, LOW);
    analogWrite(PWM1_PIN, Speed);
    analogWrite(PWM2_PIN, Speed);
    digitalWrite(STCP_PIN, LOW);
    shiftOut(DATA_PIN, SHCP_PIN, MSBFIRST, Dir);
    digitalWrite(STCP_PIN, HIGH);
}
