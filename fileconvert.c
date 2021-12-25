#include"fileconvert.h"
#include"convert.h"
#include<string.h>
static GLOBAL_PATH_TYPE np[PREBUILD_MAX];
static struct uid_cid c;
static struct file f;
void fileconvert(const GLOBAL_PATH_TYPE*const p,const struct meta*const m)
{
	file_read(&f,p);
	convert(&f,m);
	uid_utc(&(m->u),&c);
	memcpy(np,"prebuild/",9);
	memcpy(np+9,c.d,UID_CID_LENGTH);
	memcpy(np+9+UID_CID_LENGTH,".ltx",4);
	np[13+UID_CID_LENGTH]=0;
	file_write(&f,np);
	file_dec(&f);
	return;
}
