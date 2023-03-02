kathsh: kathsh.o
	gcc -o kathsh kathsh.o

kathsh.o: kathsh.c
	gcc -c kathsh.c -o kathsh.o

clean:
	rm -f kathsh *.o

