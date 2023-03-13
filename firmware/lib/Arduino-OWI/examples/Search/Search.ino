#include "GPIO.h"
#include "OWI.h"

// Configure: Software/Hardware OWI Bus Manager
#define USE_SOFTWARE_OWI
#if defined(USE_SOFTWARE_OWI)
#include "Software/OWI.h"
Software::OWI<BOARD::D7> owi;

#else
// Configure: Software/Hardware TWI Bus Manager
// #define USE_SOFTWARE_TWI
#include "TWI.h"
#include "Hardware/OWI.h"
#if defined(USE_SOFTWARE_TWI)
#include "Software/TWI.h"
#if defined(SAM)
Software::TWI<BOARD::D8,BOARD::D9> twi;
#else
Software::TWI<BOARD::D18,BOARD::D19> twi;
#endif
#else
#include "Hardware/TWI.h"
Hardware::TWI twi;
#endif
Hardware::OWI owi(twi);
#endif

void setup()
{
  Serial.begin(57600);
  while (!Serial);
}

void loop()
{
  // Scan one-wire bus and print rom code for all detected devices
  // on binary format and indicate discrepancy position.
  uint8_t rom[owi.ROM_MAX] = { 0 };
  int8_t last = owi.FIRST;
  int i = 0;
  do {
    last = owi.search_rom(0, rom, last);
    if (last == owi.ERROR) break;
    Serial.print(i++);
    Serial.print(':');
    int8_t pos = 0;
    for (size_t i = 0; i < sizeof(rom); i++)
      for (uint8_t mask = 0x80; mask != 0; mask >>= 1, pos++) {
	Serial.print((rom[i] & mask) != 0);
	if (pos == last) Serial.print('*');
      }
    if (pos == last) Serial.print('*');
    Serial.println();
  } while (last != owi.LAST);
  Serial.println();

  delay(5000);
}
