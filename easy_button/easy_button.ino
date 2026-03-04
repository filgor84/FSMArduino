#define START 0
#define FIRST_PRESS 1
#define LONG_CLICK 2
#define WAIT_2ND 3
#define SINGLE_CLICK 4
#define DOUBLE_CLICK 5
int buttonPin=7;
int raw;
int lastRaw;
uint8_t state=START;
 unsigned long lastJumpTime;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);

  
}

void loop() {
  raw=digitalRead(buttonPin);
  if (lastRaw!=raw) {
    if (raw==LOW){
      Serial.println("PUSH");
    } else
    {
      Serial.println("RELEASE");
    }
    
  }
    switch(state){
      case START:
      
      if (lastRaw!=raw && raw==LOW){
        state=FIRST_PRESS;
        Serial.println("state:FIRST_PRESS");
        lastJumpTime=millis();
      }
      break;
      case FIRST_PRESS:
    
      if (millis()-lastJumpTime>1000){
        state=LONG_CLICK;
        Serial.println("state:LONG_CLICK");
        break;
      }
      if (lastRaw!=raw && raw==HIGH){
        lastJumpTime=millis();
        state=WAIT_2ND;
        Serial.println("state:WAIT_2ND");

      }
      break;
      case LONG_CLICK:
      
      if (lastRaw!=raw && raw==HIGH){
        Serial.println("LONG CLICK");
        state=START;
        Serial.println("state:START");

      }
      break;
      case WAIT_2ND:
      if (millis()-lastJumpTime>300){
        state=SINGLE_CLICK;
        Serial.println("state:SINGLE_CLICK");
        break;
      }
      if (lastRaw!=raw && raw==LOW){
        state=DOUBLE_CLICK;
        Serial.println("state:DOUBLE_CLICK");
      }
      break;
      case SINGLE_CLICK:
      state=START;
      Serial.println("state:START");
      break;
      case DOUBLE_CLICK:
      
      if (raw==HIGH){
         Serial.println("DOUBLE CLICK");
         state=START;
         Serial.println("state:START");
      }
      break;

    }
    lastRaw=raw;
  
  }

 

