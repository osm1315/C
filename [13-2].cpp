#include <stdio.h>

#define STNUM 5
#define EXAM 3
#define NAME 5
enum yesno {NO,YES};
typedef struct student {
	char name[NAME];
	int total;
	float avg;
	int rank;
} STUD;

void read_data(char *, int []);
enum yesno calculate(int [],  int *, float *);
void ranking(STUD [], int);

int main(void)
{ 
STUD st[STNUM];
int i, j, in[EXAM], pass_num=0;
enum yesno pass;

printf("name  jumsu(3)\n");
for(i=0; i<STNUM; i++)
{
	read_data(st[pass_num].name,in);
	pass=calculate(in,&st[pass_num].total,&st[pass_num].avg);
	if(YES) 	//pass
	 	++pass_num;
}	
ranking(st, pass_num);
printf("==========================\n");
for(i=0; i<pass_num; i++)
	printf("%d: %s  %d  %.2f\n",st[i].rank,st[i].name,st[i].total,st[i].avg);
return 0;
}

void read_data(char *name, int in[])
{ 	
	scanf("%s",name);
	for(int j=0;j<EXAM;j++)
		scanf("%d",&in[j]);
	getchar();
return;
}

enum yesno calculate(int jumsu[],  int *total, float *avg)
{
	*total=0;
	for(int i=0; i<EXAM; i++)
		*total+=jumsu[i];
	*avg=(float)(*total)/EXAM;
	if(*avg>=60) return YES;
	else return NO;	
}

void ranking(STUD st[], int count)
{ 
int i, j, rank=1, same=0;
STUD tmp;

for(i=0; i<count-1; i++)   ///sorting according to score
  for(j=i+1; j<count; j++)
  	if(st[i].total<st[j].total)
  	 {
  	 	tmp=st[j];
  	 	st[j]=st[i];
  	 	st[i]=tmp;
  	 }
for(i=0; i<count; i++)
  st[i].rank=i+1;
return;
}
