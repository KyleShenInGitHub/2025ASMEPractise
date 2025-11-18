#include <Arduino.h>

static volatile int t7_cnt = 0;
static const IRQn_Type IRQn_OVF7 = IRQn_Type(16); 

static volatile int currentpwm = 0;
static volatile int count = 0;
bool isfirst = true;

void gpt7_ovf_isr() {
  R_ICU->IELSR_b[IRQn_OVF7].IR = 0;
  t7_cnt++;            // 計時器累加
}

void setup_gpt7() {
  R_MSTP->MSTPCRD_b.MSTPD6 = 0;

  R_ICU->IELSR_b[IRQn_OVF7].IELS = ELC_EVENT_GPT7_COUNTER_OVERFLOW;
  NVIC_SetVector(IRQn_OVF7, (uint32_t)gpt7_ovf_isr);
  NVIC_SetPriority(IRQn_OVF7, 12);
  NVIC_EnableIRQ(IRQn_OVF7);

  R_GPT7->GTCNT = 0;
  R_GPT7->GTPR = 48000 - 1;   // 1ms
  R_GPT7->GTCR = 0;
  R_GPT7->GTCR_b.CST = 1;
}

void hall_isr() {
  count++;
}

void setup() {
  Serial.begin(9600);
  setup_gpt7();

  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  attachInterrupt(2, hall_isr, CHANGE);
}

void loop() {
  if (isfirst) {
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    isfirst=false;
  }

  if (t7_cnt >= 10) {   // 10ms
    t7_cnt = 0;

    if (currentpwm <= 255) {
      analogWrite(5, currentpwm);
      currentpwm += 5;
      Serial.print("PWM:");
      Serial.println(currentpwm);
      Serial.print("計數");
      Serial.println(count);
    }
  }
}
