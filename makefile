all:buffer.o uid.o random.o file.o convert.o fileconvert.o
buffer.o:buffer.c
	gcc -c buffer.c -ggdb
uid.o:uid.c
	gcc -c uid.c -ggdb
random.o:random.c
	gcc -c random.c -ggdb
file.o:file.c
	gcc -c file.c -ggdb
convert.o:convert.c
	gcc -c convert.c -ggdb
fileconvert.o:fileconvert.c
	gcc -c fileconvert.c -ggdb
clean:
	rm *.o
