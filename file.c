#include"file.h"
#include"buffer.h"
#include<stdlib.h>
#include<string.h>
void file_read(struct file*const a,const char*const p)
{
	a->s=buffer_read(p);
	a->d=calloc(a->s,sizeof(char));
	memcpy(a->d,buffer,a->s*sizeof(char));
	return;
}
void file_write(const struct file*const a,const char*const p)
{
	buffer_write(a->d,a->s,p);
	return;
}
void file_dec(const struct file*const a)
{
	free(a->d);
	return;
}
