#include"convert.h"
#include<stdlib.h>
#include<string.h>
size_t convert_s1;
size_t convert_s2;
char*convert_d1;
char*convert_d2;
void convert_globalcon()
{
	convert_d1=calloc(FILE_MAX_SIZE,sizeof(char));
	convert_d2=calloc(FILE_MAX_SIZE,sizeof(char));
	return;
}
void convert_globaldec()
{
	free(convert_d1);
	free(convert_d2);
	return;
}
/*size_t convert_cover(const struct meta*const m,const size_t x,const size_t y)
{
	static struct uid_cid c;
	uid_utc(&(m->u),&c);
	memcpy(&(convert_d2[convert_s2]),"UID=",4);
	convert_s2+=4;
	memcpy(&(convert_d2[convert_s2]),c.d,sizeof(char)*64);
	convert_s2+=64;
	return y+1;
}
*/void convert(struct file*const f,const struct meta*const m)
{
	size_t f1;
	size_t f2;
	size_t f3;
	memcpy(convert_d1,f->d,f->s*sizeof(char));
	free(f->d);
	convert_s1=f->s;
	convert_s2=0;
	for(f1=0;f1<convert_s1;f1++)
		if(convert_d1[f1]!='@')
			convert_d2[convert_s2++]=convert_d1[f1];
		else
		{
			if((f1+1<convert_s1)&&(convert_d1[f1+1]=='@'))
			{
				convert_d2[convert_s2++]='@';
				f1++;
				continue;
			}
			for(f2=f1+1;(f2<convert_s1)&&(convert_d1[f2]!='{');f2++);
			if(f2==convert_s1)
			{
				printf("[Error] Find an \'@\' without a following \'{\'.\n");
				return;
			}
			for(f3=f2+1;(f3<convert_s1)&&(convert_d1[f3]!='}');f3++);
			if(f3==convert_s1)
			{
				printf("[Error] Find an \'{\' without a following \'}\'.\n");
				return;
			}
		}
	f->s=convert_s2;
	f->d=calloc(f->s,sizeof(char));
	memcpy(f->d,convert_d2,f->s*sizeof(char));
	return;
}
