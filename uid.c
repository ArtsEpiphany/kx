#include"global.h"
#include"uid.h"
int uid_uid_equal(const struct uid_uid*const a,const struct uid_uid*const b)
{
	int f1;
	for(f1=0;f1<UID_UID_LENGTH;f1++)
		if(a->d[f1]!=b->d[f1])
			return 0;
	return 1;
}
void uid_utc(const struct uid_uid*const a,struct uid_cid*const b)
{
	const UID_UID_TYPE bits=(((UID_UID_TYPE)1)<<UID_CID_BITS)-1;
	int f1;
	int f2;
	int f3;
	for(f1=f2=f3=0;f1<UID_CID_LENGTH;f1++)
	{
		b->d[f1]=uid_array[(a->d[f3]>>f2)&bits];
		f2+=UID_CID_BITS;
		if(f2==UID_UID_BITS)
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
	for(f1=f3=0;f1<UID_UID_LENGTH;f1++)
		for(f2=0,b->d[f1]=0;f2<UID_UID_BITS;f2+=UID_CID_BITS,f3++)
			b->d[f1]|=uid_inv(a->d[f3])<<f2;
	return;
}
