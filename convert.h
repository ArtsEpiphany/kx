#ifndef _CONVERT_H_
#define _CONVERT_H_
#include"global.h"
#include"file.h"
#include"meta.h"
extern size_t convert_s1;
extern size_t convert_s2;
extern char*convert_d1;
extern char*convert_d2;
void convert_globalcon();
void convert_globaldec();
void convert(struct file*const f,const struct meta*const m);
#endif
