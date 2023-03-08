#include "stdio.h"

extern void internal_message()
{
    printf("internal_message from lib.c\n");
}

extern void message()
{
    printf("Calling internal_message in lib.c!\n");
    internal_message();
}