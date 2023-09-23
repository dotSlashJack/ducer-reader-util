#ifndef SERIAL_H
#define SERIAL_H

#include <stddef.h>

int uart_init(char *portname);

int uart_read(int uart_fd, char *buffer, size_t bufsize);

void uart_close(int uart_fd);

#endif // SERIAL_H