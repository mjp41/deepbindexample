#include "stdio.h"

extern void message()
{
    puts("preload.c: message");
}

extern void internal_message()
{
    puts("preload.c: internal_message");
}