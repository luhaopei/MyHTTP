#ifndef COMMON_H__
#define COMMON_H__

#include "config.h"

#include "log.h"
#include "tcp_server.h"
#include "inetaddress.h"
#include "channel_map.h"

#include    <sys/types.h>    /* basic system data types */
#include    <sys/socket.h>    /* basic socket definitions */
#include    <sys/time.h>    /* timeval{} for select() */
#include    <time.h>        /* timespec{} for pselect() */
#include    <netinet/in.h>    /* sockaddr_in{} and other Internet defns */
#include    <arpa/inet.h>    /* inet(3) functions */
#include    <errno.h>
#include    <fcntl.h>        /* for nonblocking */
#include    <netdb.h>
#include    <signal.h>
#include    <stdio.h>
#include    <stdlib.h>
#define __USE_GNU
#include    <string.h>
#include    <sys/stat.h>    /* for S_xxx file mode constants */
#include    <sys/uio.h>        /* for iovec{} and readv/writev */
#include    <unistd.h>
#include    <sys/wait.h>
#include    <sys/un.h>        /* for Unix domain sockets */

#include    <sys/select.h>    /* for convenience */
#ifdef HAVE_SYSCONF
#include <sys/sysctl.h>
#endif
#include    <poll.h>        /* for convenience */
#include    <strings.h>        /* for convenience */
#include    <sys/ioctl.h>
#include    <pthread.h>

#ifdef EPOLL_ENABLE
#include    <sys/epoll.h>
#endif


void err_dump(const char *, ...);

void err_msg(const char *, ...);

void err_quit(const char *, ...);

void err_ret(const char *, ...);

void err_sys(const char *, ...);

void error(int status, int err, char *fmt, ...);

char *sock_ntop(const struct sockaddr_in *sin, socklen_t salen);

size_t readn(int fd, void *vptr, size_t n);

size_t read_message(int fd, char *buffer, size_t length);

size_t readline(int fd, char *buffer, size_t length);

int tcp_server(int port);

int tcp_server_listen(int port);

int tcp_nonblocking_server_listen(int port);

void make_nonblocking(int fd);

int tcp_client(char *address, int port);

#define    SERV_PORT      43211
#define    MAXLINE        4096
#define    UNIXSTR_PATH   "/var/lib/unixstream.sock"
#define    LISTENQ        1024
#define    BUFFER_SIZE    4096

#endif //COMMON_H__
