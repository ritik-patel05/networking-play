#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int port = 7000;
    int sockfd;
    struct sockaddr_in my_addr, remote_addr;
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&my_addr, '\0', sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr));
    addr_size = sizeof(remote_addr);
    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&remote_addr, &addr_size);
    printf("got data from %s", buffer);

    return 0;
}
