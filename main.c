#include "dlfcn.h"
#include "stdlib.h"
#include "stdio.h"

int main()
{
    int flags = RTLD_NOW;
#ifdef USE_DEEPBIND
    flags = flags | RTLD_DEEPBIND;
#endif

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

    exposed();

    puts("Success!");
    return 0;
}
