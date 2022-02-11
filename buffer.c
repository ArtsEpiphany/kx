#include"buffer.h"
#include<stdio.h>
#include<stdlib.h>
char*buffer;
void buffer_globalcon()
{
	buffer=calloc(FILE_MAX_SIZE,sizeof(char));
	return;
}
void buffer_globaldec()
{
	free(buffer);
	return;
}
size_t buffer_read(const char*const p)
{
	FILE*fp;
	size_t length;
	fp=fopen(p,"rb");
	length=fread(buffer,sizeof(char),FILE_MAX_SIZE,fp);
	fclose(fp);
	return length;
}
size_t buffer_write(const char*const d,const size_t s,const char*const p)
{
	FILE*fp;
	size_t length;
	fp=fopen(p,"wb");
	length=fwrite(d,sizeof(char),s,fp);
	fclose(fp);
	return length;
}
