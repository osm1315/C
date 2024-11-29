#include <stdio.h>
#define ST_NUM 5
#define EXAM_NUM 3

int total_cal(int []);
void avg_cal(int *, float *);

int main(void)
{
 int jumsu[EXAM_NUM], total[EXAM_NUM]={0,}, i, j, tt;
 float avg[ST_NUM]={0.}, ta;
 char name[ST_NUM], tmp;
 
 for(i=0; i<ST_NUM; i++)
{	
	printf("name:\n");
	scanf("%c",&name[i]);
	for(j=0; j<EXAM_NUM;j++)
		scanf("%d", &jumsu[j]);
	getchar();
	
	total[i]=total_cal(jumsu);
}
	avg_cal(total,avg);
	
	for(i=0; i<ST_NUM-1; i++)		//sorting
	  for(j=i+1; j<ST_NUM; j++)
	  		if(name[i]>name[j])
	  		{	tmp=name[j]; 		tt=total[j];  	ta=avg[j];
	  		 	name[j]=name[i]; 	total[j]=total[i];  avg[j]=avg[i];
	  		 	name[i]=tmp;		total[i]=tt;	avg[i]=ta;
			  }
	
	for(i=0; i<ST_NUM-1; i++)
		printf("name:%c total:%d avg:%.2f\n", name[i],total[i],avg[i]);
return 0;	
}

int total_cal(int *jumsu)
{
	int i, sum=0;
	for(i=0; i<EXAM_NUM; i++)
		sum+=jumsu[i];
	return sum;
}

void avg_cal(int total[], float avg[])
{
	int i;
	for(i=0; i<ST_NUM; i++)
		avg[i]=(float)total[i]/EXAM_NUM;
	return;
}
