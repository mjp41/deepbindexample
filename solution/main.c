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

    puts("Calling message directly!");
    message();
    puts("Called message directly!");
    puts("Calling message indirectly through deepbindlib!");
    exposed();
    puts("Called message indirectly through deepbindlib!");

    puts("Success!");
    return 0;
}
