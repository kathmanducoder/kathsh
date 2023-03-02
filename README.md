## kathsh

### Description
Building my own UNIX shell.

### Installation
The project comes with a Makefile which will generate an executable called kathsh.

```
➜  kathsh git:(main) ✗ make
gcc -c kathsh.c -o kathsh.o
gcc -o kathsh kathsh.o
➜  kathsh git:(main) ✗ ./kathsh 
kathsh $
```
