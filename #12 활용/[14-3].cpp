#include <stdio.h>
#include <string.h>
#define NUM 10
#define DNUM 4
#define LENG 10
void merge_sort(int, int, int, int,char (*)[LENG], char (*)[LENG]);
void copy_result(int, int, char (*)[LENG], char(*)[LENG]);

char dname[NUM][LENG], sname[NUM][LENG]; //because of uses in all functions
int main(void)
{
	char dept[][LENG]={"CS","ECE","IS","MA"}, tmp[LENG];
	int i, j, k, deptsnum[DNUM]={0}, start;
	int start1, last1, start2, last2;
	
	printf("Input dname, sname of student %d\n", NUM);
	for(i=0; i<NUM; i++)
	{
		scanf("%s %s", dname[i], sname[i]);
		for(j=0; j<DNUM; j++)	//count the st. number for each dept.
			if(!strcmp(dname[i],dept[j]))	//Found
			{
				++deptsnum[j];
				break;
			}	
	}

	for(i=0; i<NUM-1; i++)		//sort by dept. name
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

 	start=0;			
	for(k=0; k<DNUM; k++)		//sort by stu. name for each dept. k
	{
	  	for(i=start; i<start+deptsnum[k]-1; i++)	//number of st. in dept. k
			for(j=i+1; j<start+deptsnum[k]; j++)
				if(strcmp(sname[i],sname[j])>0)
				{
					strcpy(tmp,sname[j]); 
					strcpy(sname[j],sname[i]);
					strcpy(sname[i],tmp);
				}
	  	start+=deptsnum[k];	
	}
	printf("===By dept. name & student name===\n");
	start=0;
	for(j=0; j<DNUM; j++)
	{
		printf("<%s>\n",dept[j]);
		for(i=start; i<start+deptsnum[j]; i++)
			printf("%s\n", sname[i]);
		start+=deptsnum[j];
	}
	//For 1st pair merge sort
	char tdname[NUM][LENG], tsname[NUM][LENG];	
	start1=0; last1=deptsnum[0]-1; 
	start2=last1+1;	last2=start2+deptsnum[1]-1;
	merge_sort(start1,last1,start2,last2,tdname,tsname);
	copy_result(start1, last2, tdname, tsname); //copy sort result to original array
	start1=last2+1; last1=start1+deptsnum[2]-1;
	start2=last1+1;	last2=start2+deptsnum[3]-1;
	merge_sort(start1,last1,start2,last2,tdname,tsname);
	copy_result(start1, last2, tdname, tsname);
	//For 2nd pair merge sort
	start1=0; last1=deptsnum[0]+deptsnum[1]-1;
	start2=last1+1;	last2=NUM-1;
	merge_sort(start1,last1,start2,last2,tdname,tsname);
	copy_result(start1, last2, tdname, tsname); //copy funal sort result to original array
	
	printf("===Merge Result BY St. name===\n");
	for(i=0; i<NUM; i++)
			printf("%s : %s\n",sname[i],dname[i]);
return 0;
}
void merge_sort(int sa, int la, int sb, int lb,char (*dn)[LENG], char (*sn)[LENG])
{
	int i, index=0, cmp;
	
	while(sa<=la && sb<=lb)	//both are in progress
	{
		cmp=strcmp(sname[sa],sname[sb]);
		if(cmp>0) 	//b is copied
		{
			strcpy(sn[index],sname[sb]);
			strcpy(dn[index++],dname[sb++]);
		}
		else if(cmp<0)	//a is copied
		{
			strcpy(sn[index],sname[sa]);
			strcpy(dn[index++],dname[sa++]);
		}
		else	//both are copied
		{
			strcpy(sn[index],sname[sa]);
			strcpy(dn[index++],dname[sa++]);
			strcpy(sn[index],sname[sb]);
			strcpy(dn[index++],dname[sb++]);
		}
    } 
	if((sa<=la))	//b part is finished, so copy a part without comparison
		for(i=sa;i<=la;i++)
		{
			strcpy(sn[index],sname[sa]);
			strcpy(dn[index++],dname[sa++]);
		}
	else if((sb<=lb))  ////a part is finished, so copy b part without comparison
		for(i=sb;i<=lb;i++)
		{
			strcpy(sn[index],sname[sb]);
			strcpy(dn[index++],dname[sb++]);
		}
return;
}
	
void copy_result(int start, int last, char (*tdname)[LENG], char(*tsname)[LENG])
{
	int i,num;
	num=last-start;
	for(i=0; i<=num; i++)
		{
			strcpy(dname[start],tdname[i]);
			strcpy(sname[start++],tsname[i]);
		}
return;
}	

