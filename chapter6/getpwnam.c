#include "apue.h"
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd*
mygetpwnam(const char *name)
{
    struct passwd *ptr;

    setpwent();
    while ((ptr = getpwent()) != NULL)
    {
        if (strcmp(name, ptr->pw_name) == 0)
        {
            break;
        }
    }
    endpwent();
    return ptr;
}

int
main()
{
    struct passwd* ptr;

    ptr = mygetpwnam("maple");

    printf("uid: %d, gid: %d, passwd: %s\n", ptr->pw_uid, ptr->pw_gid, ptr->pw_passwd);

    return 0;  
}
