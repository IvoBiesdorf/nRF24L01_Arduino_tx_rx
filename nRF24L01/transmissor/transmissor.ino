#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte adress[6] = "PIPE1"; 

struct values{
  int potiX;
  int potiY;
  boolean ligado;
};
values dados;
void setup() {
  Serial.begin(9600);
  Serial.println("Receptor NRF24L01");
  Serial.println("");

  if(radio.begin()){
    Serial.println("Begin");
  }
  radio.openReadingPipe(0, adress);  
  radio.setPALevel(RF24_PA_MAX);    // RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, ou RF24_PA_MAX
  radio.setDataRate(RF24_250KBPS);  // RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
  radio.startListening();   
}

void loop() {
  if (radio.available()) {
    radio.read(&dados, sizeof(dados));                        // Si un message vient d'arriver, on le charge dans la variable "message"
    Serial.print("Poti X : "); 
    Serial.println(dados.potiX); 
    Serial.print("Poti Y : "); 
    Serial.println(dados.potiY);
    Serial.print("Lig : "); 
    Serial.println(dados.ligado); 
  }
}
