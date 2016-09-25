#include "tmp101.h"

double tmp101_get_temperature(void) 
{   
    // Need to set the TMP101 pointer register to point to the temp register
    uint8_t pointer_address = 0;
    i2c_write_blocking(TMP101_ADDRESS, 0, &pointer_address, 1);

    // The TMP101 stores 12 bit samples that are retrieved in two byte blocks
    uint8_t data[2];
    i2c_read(TMP101_ADDRESS, 0, &data[0], 2);

    // the 1st byte is bits 12 to 4 of the sample and the 2nd byte is bits 4 to 0
    // see page 16 of the TMP_101 datasheet
    uint16_t temperature_bits = (data[0] << 4) | (data[1] >> 4);

    // The 12 bit sample is represented using 2s complement, for simplicity 
    // (and because there's no 12 bit int representation), scale up the sample
    // to 16 bits and adjust the bit resolution when converting later
    int16_t temperature = temperature_bits << 4;

    // shift the sample back down and convert by the TMP_101 bit resolution
    return (double) ((temperature >> 4) * 0.625);
}