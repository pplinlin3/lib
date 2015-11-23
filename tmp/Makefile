all:
	gcc -c -fno-builtin a.c
	gcc -c -fno-builtin b.c
	ld a.o b.o -e main -o test

clean:
	-rm a.o b.o test
