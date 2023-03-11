# Solution

This is based on the earlier solution, but introduces a global variable to indicate if a direct call can be made to the implementation.

## Example 

The runs of the program should look like:
```
:~/deepbindexample/solutionopt/build$ ./main
main.c: main -> message
lib.c: message -> internal_message
lib.c: internal_message -> message_impl
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
lib.c: message -> internal_message
preload.c: internal_message
```

Importantly, we can see we get `preload.c: internal_message` from inside the deepbind library. 
Also, we see `lib.c: message -> message_impl` without the preload.  That is we only take the hit on the first call.