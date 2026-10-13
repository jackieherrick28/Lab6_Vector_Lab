CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = vectorCal

$(TARGET): Lab05.o vectorCal.o
	$(CC) Lab05.o vectorCal.o -lm -o $(TARGET)

Lab05.o: Lab05.c
	$(CC) $(CFLAGS) -c Lab05.c

vectorCal.o: vectorCal.c 
	$(CC) $(CFLAGS) -c vectorCal.c

clean:
	rm -f *.o $(TARGET)