#define INT4_P13 3 
#define INT3_P14 4
#define INT2_P15 5 
#define INT1_P16 6 

#define SW_A  8
#define SW_B  9
#define SW_F  10


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INT4_P13, OUTPUT);
  pinMode(INT3_P14, OUTPUT);
  pinMode(INT2_P15, OUTPUT);
  pinMode(INT1_P16, OUTPUT);

  digitalWrite(INT4_P13, LOW);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, LOW);
  digitalWrite(INT1_P16, LOW);

  pinMode(SW_A, INPUT_PULLUP);
  pinMode(SW_B, INPUT_PULLUP);
  pinMode(SW_F, INPUT_PULLUP);

}

void fnc_stop(){
  digitalWrite(INT4_P13, LOW);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, LOW);
  digitalWrite(INT1_P16, LOW);
}

void fnc_mae(){
  digitalWrite(INT4_P13, HIGH);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, HIGH);
  digitalWrite(INT1_P16, LOW);
  delay(1000);
  digitalWrite(INT4_P13, LOW);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, LOW);
  digitalWrite(INT1_P16, LOW);
  delay(1000);
}

void fnc_usiro(){
  digitalWrite(INT4_P13, LOW);
  digitalWrite(INT3_P14, HIGH);
  digitalWrite(INT2_P15, LOW);
  digitalWrite(INT1_P16, HIGH);
  delay(1000);
  digitalWrite(INT4_P13, LOW);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, LOW);
  digitalWrite(INT1_P16, LOW);
  delay(1000);
}

void fnc_migi(){
  digitalWrite(INT4_P13, LOW);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, HIGH);
  digitalWrite(INT1_P16, LOW);
  delay(500);
  digitalWrite(INT4_P13, LOW);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, LOW);
  digitalWrite(INT1_P16, LOW);
}

void fnc_hidari(){
  digitalWrite(INT4_P13, HIGH);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, LOW);
  digitalWrite(INT1_P16, LOW);
  delay(500);
  digitalWrite(INT4_P13, LOW);
  digitalWrite(INT3_P14, LOW);
  digitalWrite(INT2_P15, LOW);
  digitalWrite(INT1_P16, LOW);
}

// the loop function runs over and over again forever
void loop() {

  if (digitalRead(SW_A)==LOW){
    fnc_mae();
    delay(1500);
    fnc_hidari();
    delay(1500);
    fnc_migi();
    delay(1500);
    fnc_usiro();
    delay(1500);
    fnc_stop();
  }
  if (digitalRead(SW_B)==LOW){
    while(digitalRead(SW_F)==HIGH){
      fnc_mae();
    }
    fnc_usiro();
    fnc_migi();
    fnc_mae();
  }


}
