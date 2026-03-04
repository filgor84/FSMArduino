//www.elegoo.com
//2016.12.8

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

void setup()
{
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);
Serial.begin(9600);
}

// define variables
int redValue=255;
int greenValue=0;
int blueValue=0;
int startColor=0;
int endColor;
int inc[3];



// main loop
void loop()
{
#define delayTime 10 // fading time between colors
inc[0]=0;
inc[1]=0;
inc[2]=0;

endColor=(startColor+random(1,3))%3;

inc[startColor]=-1;
inc[endColor]=+1;
// this is unnecessary as we've either turned on RED in SETUP
// or in the previous loop ... regardless, this turns RED off
// analogWrite(RED, 0);
// delay(1000);
Serial.println(String(startColor));
Serial.println(String(endColor));
for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
{
  
redValue+=inc[0];
greenValue+=inc[1];
blueValue+=inc[2];
// The following was reversed, counting in the wrong directions
// analogWrite(RED, 255 - redValue);
// analogWrite(GREEN, 255 - greenValue);
analogWrite(RED, redValue);
analogWrite(GREEN, greenValue);
analogWrite(BLUE, blueValue);
delay(delayTime);
}

startColor=endColor;
}

