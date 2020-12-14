//
// Created by Ruochen WANG (ruochwang@gmail.com) 2020.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define BACKLOG 10

#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)

void *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in *) sa)->sin_addr);
    }
    return &(((struct sockaddr_in6 *) sa)->sin6_addr);
}


class ClientSocket {
public:

    explicit ClientSocket(const char* ip, int port);
    void init(const char* ip, const char* port);

    void send(unsigned char * data, uint64_t size);

    void recv(unsigned char* data, uint64_t size);

    void close_socket();
private:
    int fd;
};

class ServerSocket {
public:

    explicit ServerSocket(const char* ip, int port);
    void init(const char* port);

    void send(unsigned char * data, uint64_t size);

    void recv(unsigned char* data, uint64_t size);

    void close_socket();
private:
    int fd;
};

// TODO change to cpp error handling style instead of c style
void ClientSocket::init(const char* ip, const char* port) {
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(ip, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "Getaddrinfo: %s\n", gai_strerror(rv));
        return;
    }

    // Loop through all the results and connect to the first we can
    for (p = servinfo; p != nullptr; p = p->ai_next) {
        fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (fd == -1) {
            perror("client: socket");
            continue;
        }

        int ret = connect(fd, p->ai_addr, p->ai_addrlen);
        if (ret == -1) {
            close(fd);
            perror("client: connect");
            continue;
        }
        break;
    }

    if (p == nullptr) {
        fprintf(stderr, "client: failed to connect\n");
        return;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *) p->ai_addr), s, sizeof(s));
    printf("client: connecting to %s\n", s);

    freeaddrinfo(servinfo);
}

void ClientSocket::close_socket() {
    if (close(fd) != 0) perror("client close went wrong");
    // else printf("client close\n");
}

void ClientSocket::send(unsigned char *data, uint64_t size) {
    int nwritten, totlen = 0;
    while (totlen != size) {
        nwritten = write(fd, data, size - totlen);
        if (nwritten == 0) return ;
        if (nwritten == -1) return ;
        totlen += nwritten;
        data += nwritten;
        // this->send_bytes += nwritten;
    }
}

void ClientSocket::recv(unsigned char* data, uint64_t size) {
    int nread, totlen = 0;
    while (totlen != size) {
        nread = read(fd, data, size - totlen);
        if (nread == 0) return ;
        if (nread == -1) return ;
        totlen += nread;
        data += nread;
        // this->recv_bytes += nread;
    }
}



// TODO change to cpp error handling style instead of c style
void ServerSocket::init(const char* port) {
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints, *res, *p;
    int sockfd = -1;
    char s[INET6_ADDRSTRLEN];
    int yes;

    memset(&hints, 0, sizeof(hints));
    hints.ai_addr = reinterpret_cast<sockaddr *>(AF_INET);
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(nullptr, port, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "get addr info error: %s\n", gai_strerror(status));
        exit(1);
    }

    for (p = res; p != nullptr; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("server: socket");
            continue;
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }
        break;
    }

    freeaddrinfo(res);

    if (p == nullptr) {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("server: waiting for connections...\n");

    for (;;) { // main accept() loop
        addr_size = sizeof(their_addr);
        fd = accept(sockfd, (struct sockaddr *) &their_addr, &addr_size);
        if (fd == -1) {
            perror("accept");
            continue;
        }

        inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *) &their_addr), s, sizeof(s));
        printf("server: got connection from %s\n", s);
        close(sockfd);
        break;
    }
}

void ServerSocket::close_socket() {
    if (close(fd) != 0) perror("server close went wrong");
    // else printf("client close\n");
}

void ServerSocket::send(unsigned char *data, uint64_t size) {
    int nwritten, totlen = 0;
    while (totlen != size) {
        nwritten = write(fd, data, size - totlen);
        if (nwritten == 0) return ;
        if (nwritten == -1) return ;
        totlen += nwritten;
        data += nwritten;
        // this->send_bytes += nwritten;
    }
}

void ServerSocket::recv(unsigned char* data, uint64_t size) {
    int nread, totlen = 0;
    while (totlen != size) {
        nread = read(fd, data, size - totlen);
        if (nread == 0) return ;
        if (nread == -1) return ;
        totlen += nread;
        data += nread;
        // this->recv_bytes += nread;
    }
}



#endif // NETWORK_H
