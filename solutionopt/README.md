# Solution

This is based on the earlier solution, but adds a branch to check if the weak symbol has been introduced.
If it hasn't then a direct call is made, otherwise it calls the weak symbol.

## Example 

The runs of the program should look like:
```
:~/deepbindexample/solutionopt/build$ ./main
main.c: main -> message
lib.c: message -> message_impl
lib.c: message_impl
main.c: main -> exposed from deepbindlib
deepbindlib.c: exposed -> message
lib.c: message -> message_impl
lib.c: message_impl
```
and
```
deepbindexample/solutionopt/build$ LD_PRELOAD=libpreload.so ./main
main.c: main -> message
preload.c: message
main.c: main -> exposed from deepbindlib
deepbindlib.c: exposed -> message
lib.c: message -> override_message
preload.c: override_message
```

Importantly, we can see we get `preload.c: message` from inside the deepbind library.