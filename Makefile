kathshell: kathshell.o
	gcc -o kathshell kathshell.o

kathshell.o: kathshell.c
	gcc -c kathshell.c -o kathshell.o

clean:
	rm -f kathshell *.o