all:global.o uid.o random.o file.o convert.o
global.o:global.c
	gcc -c global.c -ggdb
uid.o:uid.c
	gcc -c uid.c -ggdb
random.o:random.c
	gcc -c random.c -ggdb
file.o:file.c
	gcc -c file.c -ggdb
convert.o:convert.c
	gcc -c convert.c -ggdb
clean:
	rm *.o
