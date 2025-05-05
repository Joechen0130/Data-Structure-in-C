CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lcunit

TARGET = test_stack
SRCS = stack.c test_stack.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
