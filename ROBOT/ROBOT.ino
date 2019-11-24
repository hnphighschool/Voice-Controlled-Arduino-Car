#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

void setup() {
 //BT.begin(9600);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void Forward()
{
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(100);
}

void Back()
{
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(100);
}

void Left()
{
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(800);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(100);
}

void Right(){
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(800);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  delay(100);
}

void Stop(){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(100);
}

void  Around(){
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(1600);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(100);
}
/*
Around();
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(800);
*/

void Dance(){
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(1600);
  //Forward();
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(1600);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(1000);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(1600);
  //Forward();
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(1600);
  //Left();
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(1000);
  Stop();
}

void Sleft(){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(390);  
}

void Sright(){
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(390);
}
void Snake(){
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Sleft();
  Sright();
  Stop();
}


void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c =Serial.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);
    
  if(readvoice == "*forward#")
  {
    Forward();
  }
  
  else if(readvoice == "*backward#")
  {
    Back();
  }

  else if (readvoice == "*left#")
  {
    Left();  
  }

 else if ( readvoice == "*right#")
 {
   Right();
 }

 else if (readvoice == "*stop#")
 {
   Stop();
 }
 
 else if(readvoice == "*turn around#")
 {
    Around();
 }

 else if(readvoice == "*dance#")
 {
    Dance();
 }

 else if(readvoice == "*snake#")
 {
    Snake();
 }

 readvoice="";
 }
} //Reset the variable
