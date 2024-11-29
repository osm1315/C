#include <stdio.h>
#include <string.h>
#define NUM 5
#define LENG 10
void sorting(char name[][LENG], int from, int sortnum);
int main(void)
{
	char dname[NUM][LENG], sname[NUM][LENG];
	char dept[NUM+1][LENG]={{" "}}, tmp[NUM];		//[0] dummy 
	int i, j, k, deptnum=0, deptsnum[NUM+1]={0},start, temp;
	
	printf("Input dname, sname\n");
	for(i=0; i<NUM; i++)
	{
		scanf("%s %s", dname[i], sname[i]);
		j=0;	//register new dept. name
		do		
			if(strcmp(dname[i],dept[j]))	++j;
			else 		//already registered dept.
			{ ++deptsnum[j];
			  break;
			}
		while(j<=deptnum);   
		if(j>deptnum)			//register new one
		{
			strcpy(dept[j],dname[i]);
			++deptsnum[j];
			++deptnum;
		}
	}
	for(i=0; i<NUM-1; i++)		//sort student info. by dept. name
		for(j=i+1; j<NUM; j++)
			if(strcmp(dname[i],dname[j])>0)
			{
				strcpy(tmp,dname[j]); 
				strcpy(dname[j],dname[i]);
				strcpy(dname[i],tmp);
				strcpy(tmp,sname[j]); 
				strcpy(sname[j],sname[i]);
				strcpy(sname[i],tmp);		
				}
	for(i=1; i<deptnum; i++)		//sort dept info. by dept. name (name & number of students)
		for(j=i+1; j<deptnum+1; j++)
			if(strcmp(dept[i],dept[j])>0)
			{
				strcpy(tmp,dept[j]); 
				strcpy(dept[j],dept[i]);
				strcpy(dept[i],tmp);
				temp=deptsnum[j];
				deptsnum[j]=deptsnum[i];
				deptsnum[i]=temp;
			}
	start=0;			
	for(i=0; i<deptnum; i++)		//sort by stu. name for each dept.
	{
		if(deptsnum[i+1]>1)
			sorting(sname,start,deptsnum[i+1]);
		start+=deptsnum[i+1];
    }

	printf("==========================\n");
	for(i=0; i<NUM; i++)
		printf("%s : %s\n", dname[i],sname[i]);
	printf("==========================\n\n");
	for(i=1; i<=deptnum; i++)
		printf("%s : %d\n", dept[i],deptsnum[i]);
return 0;
}

void sorting(char name[][LENG], int from, int sortnum)
{ 
	int i, j;
	char tmp[NUM];
 	for(i=from; i<from+sortnum-1; i++)	//number of st. in each dept.
		for(j=i+1; j<from+sortnum; j++)
			if(strcmp(name[i],name[j])>0)
			{
				strcpy(tmp,name[j]); 
				strcpy(name[j],name[i]);
				strcpy(name[i],tmp);
			}
return;
}
