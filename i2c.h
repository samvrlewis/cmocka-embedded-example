#ifndef I2C_H
#define I2C_H
    void i2c_transmit_blocking(uint8_t address, uint8_t offset, uin8_t* data, uint8_t data_size);
    void i2c_read_blocking(uin8_t address, uint8_t offset, uint8_t* data, uint8_t data_size);
#endif