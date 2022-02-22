#include "../gcode.h"
#include "../../MarlinCore.h"       // for pin_is_protected
#include "../../inc/MarlinConfig.h" // pin definitions
#include "../queue.h"

/**
 * M1006: Get current state of IR sensor
 *
 * I      Ingore pin protection ; should be used only for debuggin purpose
 * S<int> Sensor Number between 1 (X) and 2 (Y)
 *
 */

void GcodeSuite::M1006()
{
    if (!parser.seenval('S'))
        return;
    const int sensor = parser.intval('S');
    int val;
    if (sensor == 1)
    {
        pinMode(SERVO0_PIN, INPUT);
        extDigitalWrite(SERVO0_PIN, HIGH);
        val = extDigitalRead(SERVO0_PIN);
    };

    if (sensor == 2)
    {
        pinMode(SERVO2_PIN, INPUT);
        extDigitalWrite(SERVO2_PIN, HIGH);
        val = extDigitalRead(SERVO2_PIN);
    }
    SERIAL_DECIMAL(val);
    SERIAL_EOL();
}
