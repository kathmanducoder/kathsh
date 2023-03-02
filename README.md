## kathsh

### Description
A basic UNIX shell implementation.

### Installation
The project comes with a Makefile which will generate an executable called kathshell.

```
➜  kathsh git:(main) ✗ make
gcc -c kathsh.c -o kathsh.o
gcc -o kathsh kathsh.o
➜  kathsh git:(main) ✗ ./kathsh 
kathsh $
```
