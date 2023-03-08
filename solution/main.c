#include "dlfcn.h"
#include "stdlib.h"
#include "stdio.h"

extern void message();

int main()
{
    int flags = RTLD_NOW | RTLD_DEEPBIND;

    void* handle = dlopen("./libdeepbind.so", flags);

    if (handle == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    void (*exposed)() = dlsym(handle, "exposed");
    if (exposed == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    puts("Calling message!");
    message();
    puts("Called message!");
    puts("Calling exposed!");
    exposed();
    puts("Called exposed!");

    puts("Success!");
    return 0;
}
