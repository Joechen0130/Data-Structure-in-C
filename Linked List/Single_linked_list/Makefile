CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lcunit

SRC = src/Single_Linked_list.c src/Single_Linked_List_dump.c
TEST = test/test.c 
TARGET = ./testexe

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC) $(TEST)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
