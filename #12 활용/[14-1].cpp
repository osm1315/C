#include <stdio.h>
#include <stdlib.h>
#define TEAM 6
#define LENG 10
#define WDL 3
void ranking(int *,int (*)[WDL], int *, int);
void exchange(int *, int, int);
int main(void)
{
	int i,j, score[TEAM][WDL], total[TEAM]={0}, rank[TEAM];  //score[][j] j:0(numbr of W),1(D), 2(L)
	char name[TEAM][LENG], home[TEAM][LENG];
	
	printf("team_name, win, draw, lose, home_name\n");
	for(i=0; i<TEAM; i++)
	{
		scanf("%s",name[i]);
		for(j=0; j<WDL; j++)
		{
			scanf("%d",&score[i][j]);
			total[i]+=score[i][j]*(2-j);	//total score for each team
		}
		scanf("%s",home[i]);		
	}
	for(i=0; i<TEAM; i++)
		rank[i]=i;		//team information index for rank i
		
	ranking(total,score,rank,TEAM);
	
	printf("\n\n*Team ranking and points*\n");
	printf("==============================\n");
	for(i=0; i<TEAM; i++)
		printf("%d : %s (%d)\n", i+1, name[rank[i]],total[i]);
	printf("\n\n*Games as follows:\n");
	printf("=======================================================\n");
	for(i=0; i<TEAM/2; i++)
		printf("Game%2d:: (%s(points:%d):%s(points:%d)) At %s\n",i+1,name[rank[i]], total[i], 
		       name[rank[TEAM-1-i]],total[TEAM-1-i],home[rank[i]]);
	return 0;
}
void ranking(int *total, int (*score)[WDL], int *rank, int num)
{
	int m, n;
	
	for(m=0;m<num-1; m++)		
		  for(n=m+1; n<num; n++)
		  		if(total[m]<total[n])	
					{
						exchange(total, m, n);
						exchange(rank, m, n);
					}
		  	    else if(total[m]==total[n])
		  	    	  if(score[m][0]<score[n][0])		//n: higher rank with WIN
							{
								exchange(total, m, n);
								exchange(rank, m, n);
							}
					   else if(score[m][0]==score[n][0]) 
					   		if(score[m][1]<score[n][1])  // n: higher rank with DRAW
					   		{
					   			exchange(total, m, n);	
								exchange(rank, m, n);
							}
					        else if(score[m][1]==score[n][1])	//No teams with same win & draw!
					   		{
								printf("\n**NO TWO team with SAME score!!\n");
								exit(1);
							}
	return;
}

void exchange(int *data, int m, int n)
{	int tmp;

	tmp=data[n];
	data[n]=data[m];
	data[m]=tmp;
return;
}
