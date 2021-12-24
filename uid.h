#ifndef _UID_H_
#define _UID_H_
#include"global.h"
struct uid_uid
{
	UID_UID_TYPE d[UID_UID_LENGTH];
};
struct uid_cid
{
	UID_CID_TYPE d[UID_CID_LENGTH];
};
int uid_uid_equal(const struct uid_uid*const a,const struct uid_uid*const b);
void uid_utc(const struct uid_uid*const a,struct uid_cid*const b);
void uid_ctu(const struct uid_cid*const a,struct uid_uid*const b);
#endif
