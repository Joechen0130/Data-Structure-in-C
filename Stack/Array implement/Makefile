CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lcunit

SRC = src/Stack_array.c
TEST = test/test.c
TARGET = testexe

all: $(TARGET)

$(TARGET): $(SRC) $(TEST)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
