#include "i2c.h"

/* 
 * Writes data at the offset specified in blocking mode
 */
void i2c_transmit_blocking(uint8_t address, uint8_t offset, uint8_t* data, uint8_t data_size)
{
    // normally there would be an implementation of this function but as this project
    // is only to show how to use cmocka to write tests, an implementation of this function
    // is not needed as it is mocked out by the tests
}

/*
 * Reads data into pData from the specified i2c address in blocking mode
 */
void i2c_read_blocking(uint8_t address, uint8_t offset, uint8_t* pData, uint8_t data_size)
{
    // normally there would be an implementation of this function but as this project
    // is only to show how to use cmocka to write tests, an implementation of this function
    // is not needed as it is mocked out by the tests
}
