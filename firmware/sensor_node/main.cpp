#include "config.h"
#include "sensornode.h"

using namespace mirra;

void setup(void)
{
    constexpr MIRRAModule::MIRRAPins pins = {.bootPin = BOOT_PIN,
                                             .peripheralPowerPin = PERIPHERAL_POWER_PIN,
                                             .sdaPin = SDA_PIN,
                                             .sclPin = SCL_PIN,
                                             .csPin = CS_PIN,
                                             .rstPin = RST_PIN,
                                             .dio0Pin = DIO0_PIN,
                                             .txPin = TX_PIN,
                                             .rxPin = RX_PIN,
                                             .rtcIntPin = RTC_INT_PIN,
                                             .rtcAddress = RTC_ADDRESS};
    MIRRAModule::prepare(pins);
    SensorNode sensorNode = SensorNode(pins);
    sensorNode.wake();
}

void loop(void) {}
