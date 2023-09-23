// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "socket.h"
#define PORT 8080

int server_fd, new_socket;
struct sockaddr_in address;

int socket_init() {
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        return -1;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        return -1;
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        return -1;
    }

    printf("Waiting for client to connect...\n");
  
    new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (new_socket < 0) {
        perror("accept");
        close(server_fd);
        return -1;
    }

    printf("Client connected!\n");
    return 0;
}

int socket_send(char* message) {
    int bytes_sent = send(new_socket, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("Error sending data");
        return -1;
    } else {
        printf("Sent %d bytes to client\n", bytes_sent);
    }
    return 0;
}

void socket_close() {
    if (new_socket > 0) {
        close(new_socket);
        printf("Client socket closed.\n");
    }

    if (server_fd > 0) {
        close(server_fd);
        printf("Server socket closed.\n");
    }
}
