#include "serial.h"
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int uart_init(char *portname){
    int uart_fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);

    struct termios options;

    tcgetattr(uart_fd, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD; // baud rate (9600), 8-bit chars, enable receiver, no modem control lines
    options.c_iflag = IGNPAR; // ignore partity errors (potentially dangerous!)
    options.c_oflag = 0;
    options.c_lflag = 0;

    tcflush(uart_fd, TCIFLUSH);
    tcsetattr(uart_fd, TCSANOW, &options);
    
    return uart_fd;
}

int uart_read(int uart_fd, char *buffer, size_t bufsize) {
    return read(uart_fd, buffer, bufsize);
}

void uart_close(int uart_fd) {
    close(uart_fd);
}