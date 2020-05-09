#include <grp.h>
#include <stdio.h>
#include <string.h>


struct group*
mygetgrnam(const char* name)
{
    struct group* ptr = NULL;
    
    setgrent();
    while ((ptr = getgrent()) != NULL)
    {
        if (strcmp(name, ptr->gr_name) == 0)
            break;
    }

    return ptr;
}

int
main()
{
    struct group* ptr = mygetgrnam("maple");
    int i = 0;

    printf("gr_name: %s;\tgr_passwd: %s;\tgr_gid: %d\n", ptr->gr_name, ptr->gr_passwd, ptr->gr_gid);
    
    while ((ptr->gr_mem)[i] != NULL)
    {
        printf("user_name: %s\t", (ptr->gr_mem)[i]);
        i++;
    }

    return 0;
}
