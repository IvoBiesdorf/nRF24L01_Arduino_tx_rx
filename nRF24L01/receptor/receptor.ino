#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte adress[6] = "PIPE1"; 

struct values{    //É possível enviar até 32 bytes por vez
  int potiX;      //2 bytes
  int potiY;      //2 bytes
  boolean ligado; //1 byte
};

values dados = { 255 , 0 , false };

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(adress);    
  radio.setPALevel(RF24_PA_MAX);    // RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, ou RF24_PA_MAX
  radio.stopListening();              
  radio.setDataRate(RF24_250KBPS);  //RF24_250KBPS, RF24_1MBPS, RF24_2MBPS
}

void loop() {
  radio.write(&dados, sizeof(dados));  
  dados.potiX++;
  dados.potiY++;
  dados.ligado = !dados.ligado;
  delay(1000);                               
}
