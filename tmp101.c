#include "tmp101.h"

double tmp101_get_temperature(void) 
{   
    // Need to set the TMP101 pointer register to point to the temp register
    uint8_t pointer_address = 0;
    i2c_write_blocking(TMP101_ADDRESS, 0, &pointer_address, 1);

    // The TMP101 stores 12 bit samples that are retrieved in two byte blocks
    uint8_t data[2];
    i2c_read(TMP101_ADDRESS, 0, &data[0], 2);

    // the first byte read is bits 12 to 4 and the second byte has bits 4 to 0
    // see page 16 of the tmp_101 datasheet
    uint16_t temperature = (data[0] << 4) | (data[1] >> 4);
}