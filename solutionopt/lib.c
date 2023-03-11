#include "stdio.h"
#include "stdbool.h"

__attribute__((visibility("hidden")))
bool direct_call = false;

__attribute__((visibility("hidden")))
void message_impl()
{
    puts("lib.c: message_impl");
}

extern void internal_message()
{
    direct_call = true;
    puts("lib.c: internal_message -> message_impl");
    message_impl();
}

extern void message()
{
    if (!direct_call)
    {
        puts("lib.c: message -> internal_message");
        internal_message();
        return;
    }
    puts("lib.c: message -> message_impl");
    message_impl();
}