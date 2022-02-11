#ifndef _UID_H_
#define _UID_H_
#include"global.h"
struct uid_uid
{
	unsigned long long int d[4];
};
struct uid_cid
{
	char d[64];
};
extern const char uid_array[16];
unsigned long long int uid_inv(const char a);
int uid_uid_equal(const struct uid_uid*const a,const struct uid_uid*const b);
void uid_utc(const struct uid_uid*const a,struct uid_cid*const b);
void uid_ctu(const struct uid_cid*const a,struct uid_uid*const b);
#endif
