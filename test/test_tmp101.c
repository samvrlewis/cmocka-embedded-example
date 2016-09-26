#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "tmp101.h"

static void check_i2c_transmit(void)
{
    expect_value(__wrap_i2c_transmit_blocking, address, 0x48);
    expect_value(__wrap_i2c_transmit_blocking, offset, 0);
}

static void test_negative_temperature(void **state)
{
    will_return(__wrap_i2c_read_blocking, 0b11100111);
    will_return(__wrap_i2c_read_blocking, 0b00000000);
    
    check_i2c_transmit();
    
    assert_true(tmp101_get_temperature() == -25);
}

static void test_zero_temperature(void **state)
{
    will_return(__wrap_i2c_read_blocking, 0b00000000);
    will_return(__wrap_i2c_read_blocking, 0b00000000);
    
    check_i2c_transmit();

    assert_true(tmp101_get_temperature() == 0);
}

static void test_positive_temperature(void **state)
{
    will_return(__wrap_i2c_read_blocking, 0b01001011);
    will_return(__wrap_i2c_read_blocking, 0b00000000);
    
    check_i2c_transmit();

    assert_true(tmp101_get_temperature() == 75);
}

static void test_fractional_temperature(void **state)
{
    will_return(__wrap_i2c_read_blocking, 0b00000000);
    will_return(__wrap_i2c_read_blocking, 0b01000000);
    
    check_i2c_transmit();

    assert_true(tmp101_get_temperature() == 0.25);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_positive_temperature),
        cmocka_unit_test(test_negative_temperature),
        cmocka_unit_test(test_zero_temperature),
        cmocka_unit_test(test_fractional_temperature)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}