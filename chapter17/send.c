#include "apue.h"

struct msghdr {
    void         *msg_name;
    socklen_t     msg_namelen;
    struct iovec *msg_iov;
    int           msg_iovlen;
    void         *msg_control;
    socklen_t     msg_controllen;
    int           msg_flags;
};

int
send_err(int fd, int errcode, const char* msg)
{
    int n;

    if ((n = strlen(msg)) > 0)
        if (writen(fd, msg, n) != n)
            return -1;

    if (errcode >= 0)
        errcode = -1;

    if (send_fd(fd, errcode) < 0)
        return -1;

    return 0;
}


