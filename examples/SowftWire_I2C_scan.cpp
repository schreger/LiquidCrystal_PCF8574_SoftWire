#if 1
#include <SoftWire.h>
#include <AsyncDelay.h>
#define LED1 PA5 // grüne LED auf dem Board

//SoftWire wire(PB9, PB8);

SoftWire wire(PA12, PA11);

void setup(void)
{
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, HIGH);

  // Set how long we are willing to wait for a device to respond
  wire.setTimeout_ms(50);
  wire.begin();

  const uint8_t firstAddr = 0x00;
  const uint8_t lastAddr = 0x7F;
  Serial.println();
  Serial.println("I2C Scanner");
  Serial.print("Interrogating all addresses in range 0x");
  Serial.print(firstAddr < 16 ? "0" : "");
  Serial.print(firstAddr, HEX);
  Serial.print(" - 0x");
  Serial.print(lastAddr, HEX);
  Serial.println(" (inclusive) ...");

  for (uint8_t addr = firstAddr; addr <= lastAddr; addr++) {
    uint8_t ack = wire.llStart(addr << 1); // Signal a read
    wire.stop();
    if (ack == 0) {
      Serial.print("Device found at 0x");
      Serial.print(addr < 16 ? "0" : "");
      Serial.println(addr, HEX);
    }
  }
  Serial.println("Finished");
  digitalWrite(LED1, LOW);
}

void loop(void)
{
  ;
}
#endif
