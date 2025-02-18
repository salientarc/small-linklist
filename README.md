# Small linkedlist lib in C

## TODOs

- [ ] nicer Makefile
- [x] libcheck unit testing
- [x] check memleaks, etc. with valgrind
- [ ] code coverage report generation with gcov
- [ ] doxygen documentation
- [ ] upload on github with proper commit messages
- [ ] use `-g` gcc debugging option for use with `gdb`
- [ ] config file for code-formatting
- [ ] revisit codes several times, each time you will get something which can be done in a better way (performance, readability, or style)
    - [ ] while revisiting the code, we can write documentation, and log lines
- [ ] I don't like `OBJS` variable to be at one place, can be spread across multiple Makefiles
- [ ] I don't like the `#include "module/inc/module.h"` style now, "inc" word is redundant
- [ ] `struct` tags should not start with `_`, infact any identifier shouldn't start with leading `_`
- [ ] list can have a struct `ListInstance` which gives the user functions by which they can insert/delete/update/find/etc in the list
- [ ] log level lines instead of `printf()`s for debugging
- [ ] I have changed my style from `char *var` to `char* var`, also changed curly braces to start on the same line (unless it is a function defintion)
- [ ] fix github CI unit test
- [ ] cache github CI workflow/environment so that it doesn't install `valgrind` etc. on every push
- [ ] Separate debug bin build (compiled with `-g`) process and release bin build process 

## Dependencies

Document somehow that these are dependencies and need to be installed (or make a script that checks for and installs these dependencies)

- [ ] `valgrind`
- [ ] `check` testing framework lib 
- [ ] `lcov`
- [ ] `gcovr`
