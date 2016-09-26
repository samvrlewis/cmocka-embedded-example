#ifndef TMP101_H
#define TMP101_H
    #include <stdint.h>
    #include "i2c.h"
    
    #define TMP101_ADDRESS 0x48

    float tmp101_get_temperature(void);
#endif