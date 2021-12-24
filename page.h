#ifndef _PAGE_H_
#define _PAGE_H_
#include"global.h"
#include"file.h"
#include"meta.h"
struct page
{
	struct file f;
	struct meta m;
};
#endif
