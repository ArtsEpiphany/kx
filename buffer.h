#ifndef _BUFFER_H_
#define _BUFFER_H_
#include"global.h"
#include<stdio.h>
extern char*buffer;
void buffer_globalcon();
void buffer_globaldec();
size_t buffer_read(const char*const p);
size_t buffer_write(const char*const d,const size_t s,const char*const p);
#endif
