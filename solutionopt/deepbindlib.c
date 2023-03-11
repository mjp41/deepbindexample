#include <stdio.h>

extern void message();

extern void exposed()
{
    puts("deepbindlib.c: exposed -> message");
    message();
}