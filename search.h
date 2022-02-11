#ifndef _SEARCH_H_
#define _SEARCH_H_
#include"global.h"
struct search
{
	struct search*n[95];
	void*d;
	int f;
	unsigned long long int c;
};
void search_insert(struct search**const r,const char*const t,const int l,void*const d);
void*search_find(const struct search*const r,const char*const t,const int l);
void*search_findx(const struct search*const r,const char*const t,const int l);
#endif
