#ifndef _FILE_H_
#define _FILE_H_
#include"global.h"
struct file
{
	FILE_D_TYPE*d;
	FILE_S_TYPE s;
};
void file_globalcon();
void file_globaldec();
void file_read(struct file*const a,const GLOBAL_PATH_TYPE*const p);
void file_write(const struct file*const a,const GLOBAL_PATH_TYPE*const p);
void file_dec(const struct file*const a);
#endif
