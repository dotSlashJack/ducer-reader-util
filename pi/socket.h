#ifndef SOCKET_H
#define SOCKET_H

int socket_init();

int socket_send(char* message);

void socket_close();

#endif // SOCKET_H