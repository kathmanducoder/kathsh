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

### Demo Screenshot
![Screenshot](https://user-images.githubusercontent.com/125407887/222878203-034ef1f9-bbb8-4922-b75f-0872b2d90251.png)
