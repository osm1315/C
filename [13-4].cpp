#include <stdio.h>
#include <string.h>

#define STNUM 5
#define MAJOR 2
#define NAME 5

typedef struct exam {
	char no[MAJOR+2];
	char name[NAME+1];
	char major[MAJOR+1];
	int jumsu;
	int rank;
} APPLY;
typedef struct dept {
	char dname[MAJOR+1];
	int dnum;
} DEPT;

int passfail(int);
void assign(APPLY [], int);
void ranking(APPLY [], int);
void sorting_by_stno(APPLY [], int);
void sorting_by_passed(DEPT [], int);
void nestedsorting(DEPT [], int, int);

int main(void)
{ 
APPLY app[STNUM], in;
DEPT dept[STNUM+1];    //0: dummy
int pass_count=0, deptnum=0, tmp=0, i, j;

for(i=0; i<STNUM+1; i++)
{
	strcpy(dept[i].dname," ");
	dept[i].dnum=0;
}
printf("name   major   jumsu\n");
for(i=0; i<STNUM; i++)
{ scanf("%s %s %d", in.name, in.major, &in.jumsu);
  if (passfail(in.jumsu))    //determin whether pass or not
	  {
	   app[pass_count++]=in;
	   j=0;
	    do
		{		//register major name
			if(strcmp(in.major,dept[j].dname))	++j;
			else //already registered
			{ ++dept[j].dnum; 
			   break;	
		    }
		} while(j<=deptnum);
	    if(j>deptnum)			//register
		{
			strcpy(dept[j].dname,in.major);
			++dept[j].dnum;
			++deptnum;
		}
      }	//if
}	//for
printf("%d\n",deptnum);
if (pass_count) 
{
	ranking(app, pass_count);
	assign(app,pass_count);  // assign passed student number
	sorting_by_stno(app, pass_count);
	sorting_by_passed(dept,deptnum);
}
else {
	printf("ALL FAILED\n"); return 0; }

printf("************************\n");
for(i=0; i<pass_count; i++)
	printf("%s     %s     %s     %d    %d\n\n",app[i].no,app[i].name,app[i].major,app[i].jumsu,app[i].rank);
printf("************************\n");

for(i=1; i<=deptnum; i++)
	printf("%s: %d\n",dept[i].dname,dept[i].dnum);
return 0;
}

//////////////////////////////
int passfail(int score)
{
if (score>=60) return 1;
else return 0;
}

///////////////////////////
void ranking(APPLY info [], int count)
{ 
int i, j, rank=1, same=0;
APPLY tmp;

for(i=0; i<count-1; i++)   ///sorting according to score
  for(j=i+1; j<count; j++)
  	if(info[i].jumsu<info[j].jumsu)
  	 {
  	 	tmp=info[j];
  	 	info[j]=info[i];
  	 	info[i]=tmp;
  	 }
for(i=0; i<count; i++)
  info[i].rank=i+1;

return;
}
//////////////////////////
void assign(APPLY info[], int count)
{
	char temp[2];
	for(int i=0; i<count; i++)
	{
		strcpy(info[i].no,info[i].major);
		strncpy(temp,info[i].name,1);
		strcat(info[i].no,temp);
	}
}
/////////////////////////
void sorting_by_stno(APPLY info[], int count)
{
	APPLY tmp;
	int i, j;
	
	for(i=0; i<count-1; i++)   ///sorting according to st. no
      for(j=i+1; j<count; j++)
      	if(strcmp(info[i].no,info[j].no)>0)
      	{
      		tmp=info[j];
  	 		info[j]=info[i];
  	 		info[i]=tmp;
		  }
return;
}

void sorting_by_passed(DEPT dept[], int count)
{
	int index, j, start;
	DEPT tmp;
 	for(index=1; index<count; index++)   ///sorting according to passed number of st. in a dept.
  		for(j=index+1; j<count+1; j++)
  			if(dept[index].dnum<dept[j].dnum)
  	 			{
  	 			tmp=dept[j];
  	 			dept[j]=dept[index];
  	 			dept[index]=tmp;
  	 			}	
  	for(index=1; index<count; index++)	//perform nested sorting
  	{
  		start=index;
  		while(dept[index].dnum==dept[index+1].dnum)
  		{
  			++index;
  			if(index==count) break; 
		  	};  //index means the last index with the same number of pased st.
		if(start<index)	//same passed st. number exists
			nestedsorting(dept,start,index);
	}
  	return;
}

void nestedsorting(DEPT dept[], int start, int end)
{
	DEPT tmp;
	int i, j;
	for(i=start; i<end; i++)   ///sorting according to dept. name
     for(j=i+1; j<=end; j++)
  	  if(strcmp(dept[i].dname,dept[j].dname)>0)
      	{
      		tmp=dept[j];
  	 		dept[j]=dept[i];
  	 		dept[i]=tmp;
		  }
return;
}
