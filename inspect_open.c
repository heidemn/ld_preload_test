#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
 
typedef int (*orig_open_f_type)(const char *pathname, int flags);
 
int open(const char *pathname, int flags, ...)
{
    // add custom code here...
    printf("*** OPEN *** %s\n", pathname ? pathname : "(NULL)");

    orig_open_f_type orig_open;
    orig_open = (orig_open_f_type)dlsym(RTLD_NEXT, "open");
    return orig_open(pathname, flags);
}
