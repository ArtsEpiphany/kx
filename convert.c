#include"convert.h"
#include<string.h>
#include<malloc.h>
static FILE_D_TYPE*file_t1;
static FILE_D_TYPE*file_t2;
static FILE_S_TYPE file_s1;
static FILE_S_TYPE file_s2;
void convert_globalcon()
{
	file_t1=calloc(FILE_MAX_SIZE,sizeof(FILE_D_TYPE));
	file_t2=calloc(FILE_MAX_SIZE,sizeof(FILE_D_TYPE));
	return;
}
void convert_globaldec()
{
	free(file_t1);
	free(file_t2);
	return;
}
FILE_S_TYPE convert_cover(const struct meta*const m,const FILE_S_TYPE x,const FILE_S_TYPE y)
{
	static struct uid_cid c;
	uid_utc(&(m->u),&c);
	memcpy(&(file_t2[file_s2]),"UID=",4);
	file_s2+=4;
	memcpy(&(file_t2[file_s2]),c.d,sizeof(UID_CID_TYPE)*UID_CID_LENGTH);
	file_s2+=UID_CID_LENGTH;
	return y+1;
}
void convert(struct file*const f,const struct meta*const m)
{
	FILE_S_TYPE f1;
	FILE_S_TYPE f2;
	memcpy(file_t1,f->d,f->s*sizeof(FILE_D_TYPE));
	free(f->d);
	file_s1=f->s;
	file_s2=0;
	for(f1=0;f1<file_s1;f1++)
		if(file_t1[f1]!='@')
			file_t2[file_s2++]=file_t1[f1];
		else
		{
			if((f1+1<file_s1)&&(file_t1[f1+1]=='@'))
			{
				file_t2[file_s2++]='@';
				f1++;
				continue;
			}
			for(f2=++f1;file_t1[f2]!='{';f2++);
			switch(f2-f1)
			{
				case 5:
					f1=convert_cover(m,f1,f2);
			}
		}
	f->s=file_s2;
	f->d=calloc(f->s,sizeof(FILE_D_TYPE));
	memcpy(f->d,file_t2,f->s*sizeof(FILE_D_TYPE));
	return;
}
