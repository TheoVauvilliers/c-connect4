CC = g++
CFLAGS = -Wall
LDFLAGS =
OBJFILES = lib/Boardgame/Boardgame.o main.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
