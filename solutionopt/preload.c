#include "stdio.h"

extern void message()
{
    puts("preload.c: message");
}

extern void override_message() __attribute__((alias("message")));