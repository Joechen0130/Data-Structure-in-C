CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lcunit

SRC = src/Stack_linkedlist.c
TEST = test/test.c
TARGET = testexe

all: $(TARGET)

$(TARGET): $(SRC) $(TEST)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TARGET) $(LDFLAGS)

clean:
	rm $(TARGET)
