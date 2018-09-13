#include <SPI.h>

#define NANO_SCK  13
#define NANO_MOSI 11
#define NANO_MISO 12
#define NANO_SS   10

byte test_byte = 0xBB;

void setup() {
  pinMode(NANO_SCK,   INPUT);
  pinMode(NANO_MOSI,  INPUT);
  pinMode(SS,         INPUT);
  pinMode(NANO_MISO,  OUTPUT);

  // SPCR - SPI control register
  SPCR |= bit(SPIE);  // bit 7, SPIE: interrupt enable when 1
  SPCR |= bit(SPE);   // bit 6, SPE: enables SPI when 1
  // bit 5, DORD: MSB sent first when 0
  // bit 4, MSTR: slave mode when 0
  // bit 3, CPOL, data clock low idle when 0
  // bit 2, CPHA, samples on rising edge when 0
  // bit 1/0, SPI speed
}

ISR (SPI_STC_vect) {
  byte inc_data = SPDR;
  if(inc_data == 0xCC)
  {
    digitalWrite(LED_BUILTIN, ~digitalRead(LED_BUILTIN));
  }
  SPDR = test_byte;
  return;
}

void loop() {
  // put your main code here, to run repeatedly:
}
