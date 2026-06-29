# Makefile for GEC6818 Elevator System

CC = arm-linux-gnueabihf-gcc
CFLAGS = -O2 -Wall -DDEBUG
LDFLAGS = -lm -lpthread

SRCS = main.c fb.c bmp.c touch.c elevator.c debug.c
OBJS = $(SRCS:.c=.o)
TARGET = elevator

.PHONY: all clean static

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -static -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)

install: $(TARGET)
	scp $(TARGET) root@gec6818:/IOT/