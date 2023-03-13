#include "stdio.h"

__attribute__((visibility("hidden")))
void message_impl()
{
    puts("lib.c: message_impl");
}

__attribute__((weak))
extern void override_message();

extern void message()
{
    if (override_message != NULL)
    {
        puts("lib.c: message -> override_message");
        override_message();
        return;
    }
    puts("lib.c: message -> message_impl");
    message_impl();
}