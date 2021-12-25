#ifndef _CONVERT_H_
#define _CONVERT_H_
#include"global.h"
#include"file.h"
#include"meta.h"
void convert_globalcon();
void convert_globaldec();
void convert(struct file*const f,const struct meta*const m);
#endif
