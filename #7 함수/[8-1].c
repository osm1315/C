#include <stdio.h>
#include <stdlib.h>
#define STD_NUM 5
#define EXAM_NUM 3
int mid_cal(int,int,int);
float avg_cal(int, int);
int main(void)
{
	
	char name[STD_NUM],tn;
	float tavg;
	int i,j,s1,s2,s3, total=0,rank[STD_NUM], score[STD_NUM], seq, same, ts;
	
	
	for(i=0;i<STD_NUM; i++)
	{   printf("input name(1char) and 3 scores(0~100)\n");   // S 88 99 100
		scanf("%c%d%d%d",&name[i],&s1,&s2,&s3);
		getchar(); 
		
		score[i]=mid_cal(s1,s2,s3);
		total+=score[i];
	}
	tavg=avg_cal(total, STD_NUM);
	
	for(i=0;i<STD_NUM-1; i++)
	  for(j=i+1; j<STD_NUM; j++)
	  	if(score[i]<score[j])
	  	{
	  		ts=score[i];		tn=name[i];
	  		score[i]=score[j];  name[i]=name[j];
	  		score[j]=ts;		name[j]=tn;
		  }
	
	seq=1;		
	same=0;   //numbr of the same score
	for(i=0;i<STD_NUM-1; i++ )		//address the same rank
	{
		rank[i]=seq;
		if(score[i]!=score[i+1]) { //different score
			++same;	//because same =0 from beginning
			seq+=same;  //add the same number to the next rank
			same=0; 	
		}
		else ++same;	//the number of same score
	}
	rank[i]=seq; 	//last rank
	
	for(i=0;i<STD_NUM; i++)
		printf("Rank%d: Name:%c  %d\n",rank[i], name[i], score[i]);
	printf("Total_Avg:%.2f\n",tavg);
  return 0;
}

int mid_cal(int n1, int n2, int n3)
{	int mid, max, min;
	if(n1>n2)
	{	max=n1;
		min=n2;
	}
	else
	{
		max=n2;
		min=n1;
	}
	if(max>n3) 
		if(min>n3) mid=min;
		else mid=n3;
	else mid=max;
	return mid;
}

float avg_cal(int total, int n)
{
	return (float)total/n;
}
	
	
