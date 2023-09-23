CC = arm-linux-gnueabihf-gcc #gcc

CFLAGS = -Wall -Wextra

pi_listener: main.o serial.o
	$(CC) $(CFLAGS) main.o serial.o -o pi_listener

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

serial.o: serial.c
	$(CC) $(CFLAGS) -c serial.c

clean:	
	rm -f *.o pi_listener