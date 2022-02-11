#ifndef _FILE_H_
#define _FILE_H_
#include"global.h"
#include<stdio.h>
struct file
{
	size_t s;
	char*d;
};
void file_read(struct file*const a,const char*const p);
void file_write(const struct file*const a,const char*const p);
void file_dec(const struct file*const a);
#endif
