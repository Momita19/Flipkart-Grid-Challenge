#define leftMotor1  16          // L293d input 1 motors Rightx          GPIO16(D8)
#define leftMotor2  05          //GPIO05(D1)
#define rightMotor1 04           // L293d input 3 motors Left            GPIO4(D2)
#define rightMotor2 00            //GPIO0(D3)

#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80); // Listening at port 80

const char* ssid []= {"TP-link_72C0"};
const char* password []={"72913550"};

String  data ="";

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  //connectWiFi();
 
  pinMode(leftMotor1, OUTPUT);        //set motor pins as output
  pinMode(leftMotor2, OUTPUT);  
  pinMode(rightMotor1, OUTPUT);  
  pinMode(rightMotor2, OUTPUT); 
  
   server.begin();

 
}

void roFwd()
{
    digitalWrite(rightMotor1, HIGH);                    // move forward
    digitalWrite(rightMotor2, LOW);
    digitalWrite(leftMotor1, HIGH);                                
    digitalWrite(leftMotor2, LOW);                                                        
  }

  void stop()
  {
 digitalWrite(leftMotor1,LOW);   //stop
 digitalWrite(leftMotor2,LOW);
 digitalWrite(rightMotor1,LOW);
 digitalWrite(rightMotor2,LOW);
  delay(500);
 }

void left()
  {
    
  digitalWrite(leftMotor1,LOW);       //turn left
  digitalWrite(leftMotor2,HIGH);
 digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
}

  void right()
  {
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,LOW);
 digitalWrite(rightMotor2,HIGH);
 }


void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();  // Check if a client has connected
if (!client) return;
//data = checkClient ();
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers

  //if (f(xi)==(x,y,w,h))            
  roFwd();
 // else if (f(xmid)==(x,y,w,h)) 
  //left();  
  //else if (f(xf)==(x,y,w,h))
  //stop();

}

  //{
  //digitalWrite(eneLeftMotor,HIGH);
  //digitalWrite(eneRightMotor,HIGH);
  //digitalWrite(eneLeftMotor,HIGH);
  //digitalWrite(eneRightMotor,HIGH);                                           
 
//}//
