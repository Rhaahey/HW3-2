int buttonPin = 2;
int RLedPin = 9;

int currentMode = 0;
int buttonState = 0;
int lightNum = 0;
int RLightColor = 0;
int GLightColor = 0;
int BLightColor = 0;
int RCurrentColor = 0;
int GCurrentColor = 0;
int BCurrentColor = 0;
bool buttonPressed = false;
unsigned long pressingTime = 0;
int longPressInterval = 2000;
unsigned long blinkTimer = 0;
int blinkInterval = 500;
bool blinkOn = true;
const int fadeAmount = 2;
int fadeDirection = 1;
bool SandF = true;

void setup(){
  pinMode(buttonPin, INPUT);
  pinMode(RLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  checkButton();
  updateLEDColor();
  setRGBLedColor(RCurrentColor, GCurrentColor, BCurrentColor);
}

void checkButton(){
  buttonState = digitalRead(buttonPin);

  if(buttonState == LOW && !buttonPressed) {
  pressingTime = millis();
  buttonPressed = true;
  }
  if(buttonState == HIGH && buttonPressed) {
    unsigned long currentTime = millis();
    if(currentTime - pressingTime < longPressInterval) {
      changeMode();
      // Serial.println("short click");
    }
    else {
      changeColor();
      // Serial.println("long press");
    }
    buttonPressed = false;
  }
}

void setRGBLedColor(int r, int g, int b){
  analogWrite(RLedPin, r);
}

void changeColor(){
  lightNum = lightNum + 1;
  if(lightNum >= 5)
    lightNum = 0;

  if(lightNum == 0) {
    RLightColor = 0;
    GLightColor = 0;
    BLightColor = 0;
  }
  if(lightNum == 1) {
    RLightColor = 0;
    GLightColor = 255;
    BLightColor = 255;
  }
  if(lightNum == 2) {
    RLightColor = 255;
    GLightColor = 0;
    BLightColor = 255;
  }
  if(lightNum == 3) {
    RLightColor = 255;
    GLightColor = 255;
    BLightColor = 0;
  }
  if(lightNum == 4) {
    RLightColor = 0;
    GLightColor = 0;
    BLightColor = 255;
  }
  RCurrentColor = RLightColor;
  GCurrentColor = GLightColor;
  BCurrentColor = BLightColor;
}

void changeMode() {
  Serial.println(currentMode);
  currentMode = currentMode + 1;
  if(currentMode >= 4) {
    currentMode = 0;
  }
  if(currentMode == 1) {
    blinkTimer = 0;
    blinkOn = true;
  }
}

void updateLEDColor(){
  if (currentMode == 0){
  //Constant Light Mode
  RCurrentColor = RLightColor;
  GCurrentColor = GLightColor;
  BCurrentColor = BLightColor;
  }
  else if (currentMode == 1){
    bool negativeDir = false;
    
    if(RLightColor == 0) {
      RCurrentColor = RCurrentColor + fadeDirection * fadeAmount;
      if(RCurrentColor > (255 - RLightColor) || (RCurrentColor < 0)){negativeDir = true;
      }
      if(RCurrentColor < 0) RCurrentColor = 0;
      if(RCurrentColor > 255) RCurrentColor = 255;
    }
    if(GLightColor == 0) {
      GCurrentColor = GCurrentColor + fadeDirection * fadeAmount;
      if(GCurrentColor > (255 - GLightColor) || (GCurrentColor < 0)){negativeDir = true;
      }
      if(GCurrentColor < 0) GCurrentColor = 0;
      if(GCurrentColor > 255) GCurrentColor = 255;
    }
    if(BLightColor == 0) {
      BCurrentColor = BCurrentColor + fadeDirection * fadeAmount;
      if(BCurrentColor > (255 - BLightColor) || (BCurrentColor < 0)){negativeDir = true;
      }
      if(BCurrentColor < 0) BCurrentColor = 0;
      if(BCurrentColor > 255) RCurrentColor = 255;
    }
    if(negativeDir)
    fadeDirection = -fadeDirection;

    delay(10);
  }
  else if (currentMode == 2){
    bool negativeDir = false;
    
    if(RLightColor == 0) {
      RCurrentColor = RCurrentColor + fadeDirection * fadeAmount;
      if(RCurrentColor > (255 - RLightColor) || (RCurrentColor < 0)){negativeDir = true;
      }
      if(RCurrentColor < 0) RCurrentColor = 0;
      if(RCurrentColor > 255) RCurrentColor = 255;
    }
    if(GLightColor == 0) {
      GCurrentColor = GCurrentColor + fadeDirection * fadeAmount;
      if(GCurrentColor > (255 - GLightColor) || (GCurrentColor < 0)){negativeDir = true;
      }
      if(GCurrentColor < 0) GCurrentColor = 0;
      if(GCurrentColor > 255) GCurrentColor = 255;
    }
    if(BLightColor == 0) {
      BCurrentColor = BCurrentColor + fadeDirection * fadeAmount;
      if(BCurrentColor > (255 - BLightColor) || (BCurrentColor < 0)){negativeDir = true;
      }
      if(BCurrentColor < 0) BCurrentColor = 0;
      if(BCurrentColor > 255) RCurrentColor = 255;
    }
    if(negativeDir)
    fadeDirection = -fadeDirection;

    delay(4);
  }
  else if (currentMode == 3){
    bool negativeDir = false;
    
    if(RLightColor == 0) {
      RCurrentColor = RCurrentColor + fadeDirection * fadeAmount;
      if(RCurrentColor > (255 - RLightColor) || (RCurrentColor < 0)){negativeDir = true;
      }
      if(RCurrentColor < 0) RCurrentColor = 0;
      if(RCurrentColor > 255) RCurrentColor = 255;
    }
    if(GLightColor == 0) {
      GCurrentColor = GCurrentColor + fadeDirection * fadeAmount;
      if(GCurrentColor > (255 - GLightColor) || (GCurrentColor < 0)){negativeDir = true;
      }
      if(GCurrentColor < 0) GCurrentColor = 0;
      if(GCurrentColor > 255) GCurrentColor = 255;
    }
    if(BLightColor == 0) {
      BCurrentColor = BCurrentColor + fadeDirection * fadeAmount;
      if(BCurrentColor > (255 - BLightColor) || (BCurrentColor < 0)){negativeDir = true;
      }
      if(BCurrentColor < 0) BCurrentColor = 0;
      if(BCurrentColor > 255) RCurrentColor = 255;
    }
    if(negativeDir)
    fadeDirection = -fadeDirection;

    delay(1);
  }
}