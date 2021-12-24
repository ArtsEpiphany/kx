#include"random.h"
#include<stdlib.h>
#include<time.h>
void random_init()
{
	srand(time(NULL));
	return;
}
void random_gen(struct uid_uid*const a)
{
	int f1;
	int f2;
	for(f1=0;f1<UID_UID_LENGTH;f1++)
		for(f2=0,a->d[f1]=0;f2<UID_UID_BITS;f2++)
			a->d[f1]|=((UID_UID_TYPE)(rand()&1))<<f2;
	return;
}
