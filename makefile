all:global.o uid.o random.o
global.o:global.c
	gcc -c global.c -ggdb
uid.o:uid.c
	gcc -c uid.c -ggdb
random.o:random.c
	gcc -c random.c -ggdb
clean:
	rm *.o
