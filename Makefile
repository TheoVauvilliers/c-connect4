CC = g++
CFLAGS = -Wall
LDFLAGS =
OBJFILES = lib/Users/Users.o lib/Uuid/Uuid.o main.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
