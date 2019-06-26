#include <Key.h>
#include <Keypad.h>
#include<LiquidCrystal.h>
char ingreso[3];
const byte filas=4;
const byte columnas=4;
byte pinsFilas[filas]= {A0,A1,A2,A3};
byte pinsColumnas[columnas]= {7,6,5,4};

char teclas[filas] [columnas]={
  {'7','8','9','/'},
  {'4','5','6','x'},
  {'1','2','3','-'},
  {'ON','0','=','+'},
};
Keypad teclado= Keypad(makeKeymap(teclas), pinsFilas,pinsColumnas, filas, columnas);
LiquidCrystal lcd(13,12,11,10,9,8);
char clave[]= {'1','3','1'};
char tecla;
int i=0;
int flag=0;
int flag_clave_incorrecta=0;
int flag_clave_correcta=0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {

while(flag_clave_correcta==0){  
    lcd.setCursor(0, 0);
    lcd.print("INGRESE CLAVE:");
    lcd.setCursor(5, 1);
    flag_clave_correcta==0;
    i=0;
    while(i<3){
    tecla = teclado.getKey();
    if (tecla != NO_KEY)
      {
        ingreso[i]=tecla;
        i++;
        lcd.print(tecla);
                         }
  
                              }
   
  i=0;
  flag_clave_incorrecta=0;
  while((flag_clave_incorrecta==0) &&(i<3)){
  if(clave[i]!=ingreso[i]) {
    flag_clave_incorrecta=1;
    //delay(200);
    lcd.setCursor(0, 1);
    lcd.println("clave incorrecta");
    lcd.clear();                          
   }
   else{
    i++;
   }
  }
  if(i==3){
      flag_clave_correcta=1;
      //delay(200);
      lcd.setCursor(0, 0);
      lcd.println("clave correcta") ;
     // lcd.setCursor(0, 0);
      //lcd.clear();
      //lcd.println("   ingresando") ;
      //lcd.setCursor(0, 1);
      //lcd.println("   al sistema") ;
     }
    } 
}
