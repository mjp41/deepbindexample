# Deep Bind Example
Example of interaction between RTLD_DEEPBIND and LD_PRELOAD

This project can be built with CMake and a standard C compiler.

```
deepbindexample/build$ LD_PRELOAD=./libpreload.so ./main_works
Success!
```

```
deepbindexample/build$ LD_PRELOAD=./libpreload.so ./main_fails
Segmentation fault
```
