CC := gcc
CFLAGS := -Wall

TARGET := main
SRC := $(wildcard src/*.c) main.c
OBJ := $(SRC:.c=.o)
HEADER := $(wildcard include/*.h)


all: $(TARGET)
	rm -f $(OBJ) main.o

$(TARGET): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)