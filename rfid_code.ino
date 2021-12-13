#include <SPI.h>
#include <MFRC522.h>


#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);


#define SERVO_PIN 3



#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);


void setup() {
Serial.begin(9600);
SPI.begin();
  mfrc522.PCD_Init();
 finger.begin(57600);





}

void loop(){
  pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
  //Look for new cards
if ( !mfrc522.PICC_IsNewCardPresent() ){
return;
  }
  //Select one of the cards
if ( !mfrc522.PICC_ReadCardSerial() ) {
return;
  }

  String content= "";
byte letter;
for( byte i = 0; i< mfrc522.uid.size; i++ ){
content.concat(String(mfrc522.uid.uidByte[i], HEX));
if(i< mfrc522.uid.size-1 ) content+="-";
  }
content.toUpperCase();
Serial.println();
Serial.println("UID tag :'" + content + "'");


if( content == "92-A4-61-21" ){
  digitalWrite(4,HIGH);
    digitalWrite(5,LOW);




  
Serial.println("Authorized access");


  }
else
  {
Serial.println("Access denied");

  }
delay(1000);
}
