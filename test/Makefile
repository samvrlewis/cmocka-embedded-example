INCLUDE_DIRS = -I../src
INCLUDE_DIRS += -I$(CMOCKA_DIR)/include

CFLAGS	= $(INCLUDE_DIRS)

LDFLAGS	= -L$(CMOCKA_DIR)/build/src -Wl,-rpath=$(CMOCKA_DIR)/build/src -Wl,--wrap=i2c_read_blocking -lcmocka 
TARGET = test_tmp101
SRCS = mock_i2c.c test_tmp101.c ../src/i2c.c ../src/tmp101.c
OBJ	= $(SRCS:%.c=%.o)

CMOCKA_TAR = cmocka-1.1.0.tar.xz
CMOCKA_DIR = build/cmocka-1.1.0

all: $(CMOCKA_DIR) $(TARGET)
	./$(TARGET)

$(TARGET):  $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%: %.c
	$(CC) $(CFLAGS) $^

$(CMOCKA_DIR):
	mkdir -p build
	tar -xf cmocka-1.1.0.tar.xz -C build
	mkdir -p build/cmocka-1.1.0/build
	cd build/cmocka-1.1.0/build && cmake ../ && make

clean:
	rm -f $(TARGET) *.o