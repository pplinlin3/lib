all:
	gcc -c -fno-builtin -nostdlib entry.c
	gcc -c -fno-builtin -nostdlib stdio.c
	ar -rs minicrt.a entry.o stdio.o
	gcc -c -fno-builtin -nostdlib test.c
	ld -static -e mini_crt_entry test.o minicrt.a -o test

clean:
	-rm *.a *.o test
