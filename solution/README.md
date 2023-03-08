# Solution

This is a Paul Lietar's proposal for allowing override of malloc in the presence of an RTLD_DEEPBIND.

Effectively, you should make the library have the external calling symbol
  malloc
and then have an internal symbol
  internal_malloc
The `malloc` implementation should just call `internal_malloc`.

An LD_PRELOAD can then be used to override `internal_malloc` in the libc, so that all calls to the libc malloc will call the LD_PRELOAD.
This is similar to malloc_hooks, but at the LD_PRELOAD level rather than the assigning global variables level.

## Example 

This directory contains a simple example that shows this is possible.

*  lib.c - contains the library we want to override, and contains, `message` and `internal_message`. 
* deepbindlib.c - contains the library we will load with RTLD_DEEPBIND. It depends on dso from lib.c, and calls `message` from its only function `exposed`.
* preload.c - contains the library we want to provide an alternative version of message from.  We provide definitions for both `message` and `internal_message`.
* main.c - the application that just loads deepbindlib with RTLD_DEEPBIND, it depends on the dso from `lib.c`, so that the loader can apply LD_PRELOAD to its calls.

The runs of the program should look like:
```
deepbindexample/solution/build$ ./main
Calling message!
Calling internal_message in lib.c!
internal_message from lib.c
Called message!
Calling exposed!
Calling internal_message in lib.c!
internal_message from lib.c
Called exposed!
Success!
```
and
```
deepbindexample/solution/build$ LD_PRELOAD=libpreload.so ./main
Calling message!
message from preload.c
Called message!
Calling exposed!
Calling internal_message in lib.c!
internal_message from preload.c
Called exposed!
Success!
```

Importantly, we can see we get `internal_message from preload.c` from inside the deepbind library. 