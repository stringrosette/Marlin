#include "../gcode.h"
#include "../../MarlinCore.h"       // for pin_is_protected
#include "../../inc/MarlinConfig.h" // pin definitions
#include "../queue.h"

/**
 * M1007: Get current state of IR sensor
 *
 * I      Ingore pin protection ; should be used only for debuggin purpose
 * S<int> Relay Number between 1 and 4 (Y)
 *
 */

void GcodeSuite::M1007()
{
    if (!parser.seenval('S'))
        return;
    const int sensor = parser.intval('S');
    bool read;
    int RELAY_PIN;
    if (sensor == 1){
        RELAY_PIN = RELAY1_PIN;
    } else if (sensor == 2){
        RELAY_PIN = RELAY2_PIN;
    } else if (sensor == 3){
        RELAY_PIN = RELAY3_PIN;
    } else if (sensor == 3){
        RELAY_PIN = RELAY4_PIN;
    } else {
        return;
    }
    pinMode(RELAY_PIN, INPUT);
    read = extDigitalRead(RELAY1_PIN);
    pinMode(RELAY_PIN, OUTPUT);
    extDigitalWrite(RELAY_PIN, !read);
    SERIAL_EOL();
}
