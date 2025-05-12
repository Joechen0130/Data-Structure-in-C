CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lcunit

SRC = src/Queue_circular_array.c
TEST = test/test.c
TARGET = testexe

all: $(TARGET)

$(TARGET): $(SRC) $(TEST)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TARGET) $(LDFLAGS)

run: 
	./testexe
clean:
	rm $(TARGET)
