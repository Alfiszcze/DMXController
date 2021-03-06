// Display handling
// Also provides basic menu handling

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);


void showKnobs();

void displaySetup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,2);
  lcd.print("Red   Green  Blue");
}

int  slowdisplay = DISPLAYSPEED;


void showValue(int value,int xpos,int ypos){
//  int mil = millis();
  char buf[4];
  sprintf(buf,"%3u",value);
  lcd.setCursor(xpos,ypos);
  lcd.print(buf);
//  showduration(mil);  
}

void showduration(int start){
  int mil = millis()-start;
  lcd.setCursor(2,2);
  lcd.print(mil);
}

void updateKnobs(){
  if(slowdisplay == 0){
    showKnobs();
    slowdisplay = DISPLAYSPEED;
  }else{
    slowdisplay--;
  }
}

void showKnobs(){

  int knobValue;
  for(int knob = 0;knob<VALUEKNOBS;knob++){
      if(getKnobChanged(knob)){
        setKnobChanged(knob,false);
        switch(getKnobMode()){
          case 0:
            knobValue = getKnobValueLog(knob);
            break;
          case 1:
            knobValue = getKnobValue(knob);
            break;
        }
        showValue(knobValue,knob*7+1,3);
      }
  }
}

// Proxies for other modules
void lcdSetCursor(int x, int y){
  lcd.setCursor(x,y);
}
void lcdPrint(String text){
  lcd.print(text);
}

