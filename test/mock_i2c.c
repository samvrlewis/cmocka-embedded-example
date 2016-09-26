#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "i2c.h"

void __wrap_i2c_transmit_blocking(uint8_t address, uint8_t offset, uint8_t* data, uint8_t data_size)
{



}

void __wrap_i2c_read_blocking(uint8_t address, uint8_t offset, uint8_t* pData, uint8_t data_size) 
{
	// allow the calling test to specify the data it wants back
	// and copy it back out
	for(int i=0; i < data_size; i++) {
		pData[i] = mock_type(uint8_t);
	}
}
