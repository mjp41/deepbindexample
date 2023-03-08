#include "stdlib.h"
#include "stdint.h"

uintptr_t fake_ptr = ~0;

extern __attribute__((visibility("default")))
void exposed()
{
    // This will fail if it calls a real free,
    // but won't if it calls the fake free in the preload.
    free((void*)fake_ptr);
}