#include <stdio.h>
#include <stdlib.h>
#define TEAMNUM 6
#define LENG 10
#define WDL 3

typedef struct team {	
	int score[WDL], total, rank;
	char name[LENG],home[LENG];
} TEAM;
void ranking(TEAM *, int);
void exchange(TEAM *, int ,int );
int main(void)
{
	int i,j;
	TEAM teaminfo[TEAMNUM];  //score[j] j:0(numbr of W),1(D), 2(L)
	
	printf(" 6 team_name, win, draw, lose, home_name\n");
	for(i=0; i<TEAMNUM; i++)
	{
		scanf("%s",teaminfo[i].name);
		teaminfo[i].total=0;
		for(j=0; j<WDL; j++)
		{
			scanf("%d",&teaminfo[i].score[j]);
			teaminfo[i].total+=teaminfo[i].score[j]*(2-j);	//total score for each team
		}
		scanf("%s",teaminfo[i].home);		
	}

	ranking(teaminfo,TEAMNUM);
	for(i=0; i<TEAMNUM; i++)
		teaminfo[i].rank=i+1;
	
	printf("\n\n*Team ranking and points*\n");
	printf("==============================\n");
	for(i=0; i<TEAMNUM; i++)
		printf("%d : %s (%d)\n", teaminfo[i].rank, teaminfo[i].name,teaminfo[i].total);
	printf("\n\n*Games as follows:\n");
	printf("=======================================================\n");
	for(i=0; i<TEAMNUM/2; i++)
		printf("Game%2d:: (%s(points:%d):%s(points:%d)) At %s\n",i+1,teaminfo[i].name, teaminfo[i].total, 
		       teaminfo[TEAMNUM-1-i].name,teaminfo[TEAMNUM-1-i].total,teaminfo[i].home);
	return 0;
}
void ranking(TEAM *info, int num)
{
	int m, n;
	TEAM tmp;
	for(m=0;m<num-1; m++)		
		  for(n=m+1; n<num; n++)
		  		if((info+m)->total<(info+n)->total)	
					exchange(info, m, n);
		  	    else if((info+m)->total==(info+n)->total)
		  	    	  if((info+m)->score[0]<(info+n)->score[0])		//n: higher rank with WIN
						exchange(info, m, n);
					  else if((info+m)->score[0]==(info+n)->score[0]) 
					   		if((info+m)->score[1]<(info+n)->score[1])  // n: higher rank with DRAW
					   			exchange(info, m, n);
					        else if((info+m)->score[1]==(info+n)->score[1])	//No teams with same win & draw!
					   		{
								printf("\n**NO TWO team with SAME score!!\n");
								exit(1);
							}
	return;
}
void exchange(TEAM *info, int m,int n)
{ 
	TEAM tmp;
	tmp=*(info+n);
	*(info+n)=*(info+m);
	*(info+m)=tmp;
return;
}
