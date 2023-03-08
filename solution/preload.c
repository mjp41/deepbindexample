#include "stdio.h"

extern void message()
{
    printf("message from preload.c\n");
}

extern void internal_message()
{
    printf("internal_message from preload.c\n");
}