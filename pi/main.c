/**
 * Implementation of a serial port listener (used on raspberry pi to listen to an arduino)
 * by Jack Hester
*/
#include <stdio.h>
#include "serial.h"

// TODO: you should update this as applicable
char* portname = "/dev/serial/by-id/usb-Arduino__www.arduino.cc__0043_950373235353516030B1-if00";

int main() {
    int uart_fd = uart_init(portname);
    if (uart_fd == -1) {
        printf("Error - Unable to open UART\n");
        return -1;
    }

    while (1) {
        char rx_buffer[256];
        int rx_length = uart_read(uart_fd, rx_buffer, sizeof(rx_buffer) - 1);

        if (rx_length < 0) {
            printf("An error occurred during reading\n");
        } else if (rx_length == 0) {
            printf("No data is available\n");
        } else {
            rx_buffer[rx_length] = '\0';
            printf("%i bytes read : %s\n", rx_length, rx_buffer);
        }

        sleep(1);
    }

    uart_close(uart_fd);
    return 0;
}
