#include <example-music.h>
#include <piezo-music.h>


#include <LiquidCrystal_I2C.h>
int musica[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, 
  NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_C4
};

int ritmo[] = {
  4, 4, 4, 4, 
  4, 4, 2,
  4, 4, 4, 4, 
  4, 4, 2
};
LiquidCrystal_I2C lcd(0x20,16,2);

const int bt_play=13;
const int bt_pause=6;
const int bt_next =5;
const int bt_prev=4;
//FRECUENCIAS

const int b1=12;
int cantidad = sizeof(musica)/sizeof(ritmo[0]);


int b2=11;
int b3= 10;



void setup() {
pinMode(bt_play,INPUT);
pinMode(bt_pause,INPUT);
pinMode(bt_next,INPUT);
pinMode(bt_prev,INPUT);

  // put your setup code here, to run once:
lcd.init();
lcd.clear();

 delay(1000);
playSong(b1, musica, ritmo, cantidad, 40);
  delay(1000);

Serial.begin(9600);
}

void loop() {
  //prueba del todo
tone(b1,261.6,1000);
delay(1000);
 ///
if(digitalRead(bt_play)==HIGH){
  Serial.println("PLAY");
  
  delay(1000);
   }else if(digitalRead(bt_pause)==HIGH){
    Serial.println("PAUSE");
    delay(1000);
    }else if(digitalRead(bt_next)==HIGH){
      Serial.println("NEXT");
      delay(1000);
     }else if(digitalRead(bt_prev)==HIGH){
      Serial.println("PREV");
      delay(1000);
      }else{
        Serial.println("APAGADO");
        lcd.setCursor(5,0);
        lcd.print("APAGADO");
        delay(1000);
                }
              
    
     

}
