#include"global.h"
#include"uid.h"
const char uid_array[16]=
{
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'a',
	'b',
	'c',
	'd',
	'e',
	'f'
};
unsigned long long int uid_inv(const char a)
{
	if((a>='0')&&(a<='9'))
		return (unsigned long long int)(a-'0');
	else
		return (unsigned long long int)(a-'a'+10);
}
int uid_uid_equal(const struct uid_uid*const a,const struct uid_uid*const b)
{
	int f1;
	for(f1=0;f1<4;f1++)
		if(a->d[f1]!=b->d[f1])
			return 0;
	return 1;
}
void uid_utc(const struct uid_uid*const a,struct uid_cid*const b)
{
	int f1;
	int f2;
	int f3;
	for(f1=f2=f3=0;f1<64;f1++)
	{
		b->d[f1]=uid_array[(a->d[f3]>>f2)&15];
		f2+=4;
		if(f2==64)
		{
			f2=0;
			f3++;
		}
	}
	return;
}
void uid_ctu(const struct uid_cid*const a,struct uid_uid*const b)
{
	int f1;
	int f2;
	int f3;
	for(f1=f3=0;f1<4;f1++)
		for(f2=0,b->d[f1]=0;f2<64;f2+=4,f3++)
			b->d[f1]|=uid_inv(a->d[f3])<<f2;
	return;
}
