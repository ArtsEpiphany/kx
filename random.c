#include"random.h"
#include<stdlib.h>
#include<time.h>
void random_globalcon()
{
	srand(time(NULL));
	return;
}
void random_gen(struct uid_uid*const a)
{
	int f1;
	int f2;
	for(f1=0;f1<4;f1++)
		for(f2=0,a->d[f1]=0;f2<64;f2++)
			a->d[f1]|=((unsigned long long int)(rand()&1))<<f2;
	return;
}
