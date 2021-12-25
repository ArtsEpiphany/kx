#include"file.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>
static FILE_D_TYPE*file_temp;
void file_globalcon()
{
	file_temp=calloc(FILE_MAX_SIZE,sizeof(FILE_D_TYPE));
	return;
}
void file_globaldec()
{
	free(file_temp);
	return;
}
void file_read(struct file*const a,const GLOBAL_PATH_TYPE*const p)
{
	FILE*fp;
	fp=fopen(p,"rb");
	a->s=fread(file_temp,sizeof(FILE_D_TYPE),FILE_MAX_SIZE,fp);
	fclose(fp);
	a->d=calloc(a->s,sizeof(FILE_D_TYPE));
	memcpy(a->d,file_temp,a->s*sizeof(FILE_D_TYPE));
	return;
}
void file_write(const struct file*const a,const GLOBAL_PATH_TYPE*const p)
{
	FILE*fp;
	fp=fopen(p,"wb");
	fwrite(a->d,sizeof(FILE_D_TYPE),a->s,fp);
	fclose(fp);
	return;
}
void file_dec(const struct file*const a)
{
	free(a->d);
	return;
}
