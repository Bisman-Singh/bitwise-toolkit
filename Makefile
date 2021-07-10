CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = bitwise-toolkit
SRCS = main.c bitops.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c bitops.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
