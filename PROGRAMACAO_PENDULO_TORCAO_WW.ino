/*


  ~> Creditos

   Programa criado por William Wayn - Bolsista PET-Física com auxilio do tutor Francisco Laudares.

  ~> Montagem do circuito.

  PINAGENS DO SD CARD (É NECESSARIO FAZER A MONTAGEM COM DIVISOR DE TENSÃO)
 ** MOSI NO PINO 11 do arduino
 ** MISO no PINO 12 do Arduino
 ** CLK no PINO 13 do Arduino
 ** CS(CHIP_SELECT) PINO 4
   PINAGEM EXTRA
 ** LED COM *RESISTOR* NOS PINOS 10 (VERMELHO) e 9 (VERDE) e 8 (LED INFRAVERMELHO). LED IF TMB PRECISA DO RESISTOR !!!
 ** SENSOR IF no pino 5

*/



// Bibliotecas
#include <SPI.h>  // Responsavel pela comunicacao serial
#include <SD.h>  // Rotinas de 

// Variaveis
const int ledVerm = 10, ledVerd = 9, ledIF = 8, sensorIF = A5, chipSelect = 4;
int valorAnalogico = 0;
long tempo = 0;
File myFile;  //

void setup() {
  pinMode(ledVerm, OUTPUT);
  pinMode(ledVerd, OUTPUT);
  if (!SD.begin(chipSelect)) { //Caso tenha erro ligar led vermelho
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledVerd, LOW);
    while (1);
  }
  myFile = SD.open("dados1.txt", FILE_WRITE); // Abre o SD e cria o doc DADOS1.TXT
  if (myFile) {
    myFile.println("-------------- NOVOS DADOS --------------");
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledVerd, HIGH);
  }
}

void loop() {
  valorAnalogico = analogRead(sensorIF); // Fara Leitura do sensor Analogico (Sensor IF) e gravará os dados em valorAnalogico.
  myFile.print("Leitura: ");
  myFile.print(valorAnalogico);
  myFile.print(" Tempo: ");
  myFile.println(tempo);
  tempo = (tempo - millis());
}
