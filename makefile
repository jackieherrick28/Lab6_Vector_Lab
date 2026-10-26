CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = vectorCal

$(TARGET): Lab07.o vectorCal.o
	$(CC) Lab07.o vectorCal.o -lm -o $(TARGET)

Lab05.o: Lab07.c
	$(CC) $(CFLAGS) -c Lab07.c

vectorCal.o: vectorCal.c 
	$(CC) $(CFLAGS) -c vectorCal.c

clean:
	rm -f *.o $(TARGET)