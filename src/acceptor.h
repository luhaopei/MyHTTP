#ifndef ACCEPTOR_H__
#define ACCEPTOR_H__

#include "common.h"

struct acceptor{
    int listen_port;
    int listen_fd;
};

struct acceptor *acceptor_init(int port);

#endif // !ACCEPTOR_H__
