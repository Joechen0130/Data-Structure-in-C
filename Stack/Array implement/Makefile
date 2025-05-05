CC = gcc
CFLAGS = -Wall -Iinclude
LDFLAGS = -lcunit

SRC = src/your_code.c test/test.c
OUT = test

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
