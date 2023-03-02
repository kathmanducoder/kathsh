ashell: ashell.o
	gcc -o ashell ashell.o

ashell.o: ashell.c
	gcc -c ashell.c -o ashell.o

clean:
	rm -f ashell *.o

