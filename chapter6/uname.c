#include <sys/utsname.h>
#include <stdio.h>
#include <unistd.h>

#define HOST_NAME_MAX 64

int
main()
{
    struct utsname ptr;
    char name[HOST_NAME_MAX];

    uname(&ptr);
    printf("sysname: %s;\n nodename: %s;\n release: %s;\n version: %s;\n machine: %s;\n", 
                    ptr.sysname, 
                    ptr.nodename,
                    ptr.release,
                    ptr.version,
                    ptr.machine);
    
    gethostname(name, HOST_NAME_MAX);
    printf("hostname: %s\n", name);

    return 0;
}
