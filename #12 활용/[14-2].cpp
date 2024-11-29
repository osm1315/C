#include <stdio.h>
#include <string.h>
#define NUM 10
#define LENG 20

void stdinfo_sort(char [][LENG], char [][LENG], int);
void register_info(char *, char (*)[LENG],int *, int *);
void registeredinfo_sort(char (*)[LENG], int *, int);
void find_distinct(char (*)[LENG], int *, int ,int *);

int main(void)
{
	char dname[NUM][LENG],sname[NUM][LENG], dept[NUM+1][LENG]={{" "}}, std[NUM+1][LENG]={{" "}}; //dummy:0
	int i, j, dnamecount=0, snamecount=0, deptsnum[NUM+1]={0},snamenum[NUM+1]={0};
	int diffstu_indept[NUM+1]={0};
	
	printf("Input dept. name & student name\n");
	for(i=0; i<NUM; i++)
	{
		scanf("%s %s",dname[i], sname[i]);
		register_info(dname[i],dept,deptsnum,&dnamecount); //register dept_name
		register_info(sname[i],std,snamenum,&snamecount); //register student_name
	}
	
	stdinfo_sort(dname,sname,NUM);		//sort st. data by dept. name&student name
	registeredinfo_sort(dept,deptsnum,dnamecount);	//sort registered dept. name & its number
   	find_distinct(sname,deptsnum,dnamecount,diffstu_indept);
   	registeredinfo_sort(std,snamenum,snamecount);	//sort registered student name & its number
	printf("<dept name & student name>\n");
    
	int start=0;
	for(i=0; i<dnamecount; i++)
	{   
		printf("==%s==\n",dept[i+1]);
		for(j=start; j<start+deptsnum[i+1]; j++)
			printf("%s\n",sname[j]);
		start+=deptsnum[i+1];
    }
	printf("**number of distint name in each dept**\n");
	for(i=1; i<=dnamecount; i++)
		printf("%s: %d\n", dept[i],diffstu_indept[i]);
		
	printf("**number of each distinct name in all dept**\n");
	for(i=1; i<=snamecount; i++)
		printf("%s: %d\n", std[i],snamenum[i]);
return 0;
}
void register_info(char *name, char (*table)[LENG],int *numof, int *count)
{
 	int index=0;	
		do		
			if(strcmp(name,table[index]))	++index;
			else 		//already registered dept.
			{ ++numof[index];
			  break;
			}
		while(index<=*count);
		if(index>*count)			//register new one
		{
			strcpy(table[index],name);
			numof[index]++;
			(*count)++;
		}
return;
}
void stdinfo_sort(char dn[][LENG], char sn[][LENG], int num)
{
	char tmp[LENG];
	int i, j;
	
	for(i=0; i<num-1; i++)
		for(j=i+1; j<num; j++)
			if(strcmp(dn[i],dn[j])>0)
			{
				strcpy(tmp,dn[j]); 
				strcpy(dn[j],dn[i]);
				strcpy(dn[i],tmp);
				strcpy(tmp,sn[j]); 
				strcpy(sn[j],sn[i]);
				strcpy(sn[i],tmp);
			}
			else if(strcmp(dn[i],dn[j])==0 && strcmp(sn[i],sn[j])>0)	//sort stu. name in the same dept.
				{
					strcpy(tmp,sn[j]); 
					strcpy(sn[j],sn[i]);
					strcpy(sn[i],tmp);
				}
return;
}
void registeredinfo_sort(char (*name)[LENG], int *num, int numof)
{
	char tmp[LENG];
	int i, j, tp;
	
	for(i=1; i<=numof-1; i++)
		for(j=i+1; j<=numof; j++)
			if(strcmp(name[i],name[j])>0)
			{
				strcpy(tmp,name[j]); 
				strcpy(name[j],name[i]);
				strcpy(name[i],tmp);
				tp=num[j];
				num[j]=num[i];
				num[i]=tp;
			}
return;
}
void find_distinct(char (*name)[LENG], int *num, int count,int *diff_num)
{
	int i,j, start=0;

	for(i=1; i<=count; i++) //for each dept
	{
		for(j=start; j<start+num[i]-1;j++)
			if(strcmp(name[j],name[j+1]))    //different name
				diff_num[i]++;
		diff_num[i]++;	//the last name (j is increseaed) irrespective of same as before
		start+=num[i];
	}
return;
}
