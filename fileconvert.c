#include"fileconvert.h"
#include"buffer.h"
#include"convert.h"
#include<string.h>
void fileconvert(const char*const p,const struct meta*const m)
{
	static struct uid_cid c;
	static struct file f;
	file_read(&f,p);
	convert(&f,m);
	uid_utc(&(m->u),&c);
	memcpy(buffer,"prebuild/",9);
	memcpy(buffer+9,c.d,64);
	memcpy(buffer+73,".ltx",4);
	buffer[77]=0;
	file_write(&f,buffer);
	file_dec(&f);
	return;
}
