CC = arm-linux-gnueabihf-gcc #gcc

CFLAGS = -Wall -Wextra

pi_listener: main.o serial.o socket.o
	$(CC) $(CFLAGS) main.o serial.o socket.o -o pi_listener

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

serial.o: serial.c serial.h
	$(CC) $(CFLAGS) -c serial.c

socket.o: socket.c socket.h
	$(CC) $(CFLAGS) -c socket.c

clean:	
	rm -f *.o pi_listener