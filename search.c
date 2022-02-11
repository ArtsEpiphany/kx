#include"search.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search_insert(struct search**const r,const char*const t,const int l,void*const d)
{
	struct search*p;
	int f1;
	int v;
	if(*r==NULL)
	{
		*r=malloc(sizeof(struct search));
		memset(*r,0,sizeof(struct search));
	}
	for(f1=0,p=*r,p->c++;f1<l;f1++,p=p->n[v],p->c++)
	{
		v=t[f1]-'.';
		if(p->n[v]==NULL)
		{
			p->n[v]=malloc(sizeof(struct search));
			memset(p->n[v],0,sizeof(struct search));
		}
	}
	if(p->f)
		printf("[Error] In function search_insert(): Collision\n");
	else
	{
		p->f=1;
		p->d=d;
	}
	return;
}
void*search_find(const struct search*const r,const char*const t,const int l)
{
	const struct search*p;
	int f1;
	for(f1=0,p=r;f1<l;p=p->n[t[f1++]-'.'])
		if(p==NULL)
			return NULL;
	if(p==NULL)
		return NULL;
	return p->d;
}
void*search_findx(const struct search*const r,const char*const t,const int l)
{
	const struct search*p;
	int f1;
	for(f1=0,p=r;f1<l;p=p->n[t[f1++]-'.'])
		if(p==NULL)
			return NULL;
	if(p==NULL)
		return NULL;
	if(p->c>1)
	{
		printf("[Error] In function search_findx(): Ambiguous\n");
		return NULL;
	}
	while(!(p->f))
		for(f1=0;f1<95;f1++)
			if(p->n[f1]!=NULL)
			{
				p=p->n[f1];
				break;
			}
	return p->d;
}
