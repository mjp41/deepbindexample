# Deep Bind Example
Example of interaction between RTLD_DEEPBIND and LD_PRELOAD

This project can be built with CMake and a standard C compiler.

The first example overrides free with a do nothing function. The first example does not use RTLD_DEEPBIND to load the shared library, and the call to free is overridden:
```
deepbindexample/build$ LD_PRELOAD=./libpreload.so ./main_works
Success!
```

The second example uses RTLD_DEEPBIND and hence the shared library ignores the overridden `free` and crashs:
```
deepbindexample/build$ LD_PRELOAD=./libpreload.so ./main_fails
Segmentation fault
```
