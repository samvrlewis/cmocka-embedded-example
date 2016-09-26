#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "tmp101.h"

static void test_positive_temperature(void **state)
{
     will_return(__wrap_i2c_read_blocking, 0b11001001);
     will_return(__wrap_i2c_read_blocking, 0b0000000);

     float test = tmp101_get_temperature();
}

static void test_negative_temperature(void **state)
{
	 will_return(__wrap_i2c_read_blocking, 0b01001011);
     will_return(__wrap_i2c_read_blocking, 0b00000000);

     assert_in_range(tmp101_get_temperature(), 78.9, 79.5);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_positive_temperature),
        cmocka_unit_test(test_negative_temperature)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}