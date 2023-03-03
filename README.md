## kathsh

### Description
Implementation of a custom UNIX shell that supports one pipe redirection.

### Installation
The project comes with a Makefile which will generate an executable called kathsh.

```
➜  kathsh git:(main) ✗ make
gcc -c kathsh.c -o kathsh.o
gcc -o kathsh kathsh.o
➜  kathsh git:(main) ✗ ./kathsh 

Welcome to kathsh
kathsh $
```
