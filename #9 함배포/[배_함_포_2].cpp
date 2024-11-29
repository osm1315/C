#include <stdio.h>
#define ST_NUM 5
#define SUBJ_NUM 3
#define KOR 0
#define MATH 1
#define ENG 2

void sorting(int *, int *, int);
void ranking(int *, int *, int);
int main()
{
	char name[ST_NUM], dept[ST_NUM];
	int i,j;
	int stno[ST_NUM],score[SUBJ_NUM][ST_NUM],rank[SUBJ_NUM][ST_NUM];
	int rank_pos[SUBJ_NUM][ST_NUM]; 
	  	 //rank_pos(i,j):  name position in name[] of rank j for subject i
		//score(i,j): score of student j for subject i
		//rank(i,j): rank number of rank i considered the same for subject i
	printf("name(1),dept(1),stno(3) & 3 scores(K,E,M)\n");
	for(i=0; i<ST_NUM; i++)
	{
		scanf("%c %c %d",&name[i], &dept[i],&stno[i]);
		for(j=0; j<SUBJ_NUM; j++)
			scanf("%d",&score[j][i] );
		getchar();
		}
	
	for(i=0; i<SUBJ_NUM; i++)		//initialize rank position; st#1=0 in name[], st#2=1 in name[]...
		for(j=0; j<ST_NUM; j++)
			rank_pos[i][j]=j;
	
		
	for(i=0; i<SUBJ_NUM; i++)
	{
		sorting(score[i],rank_pos[i],ST_NUM );
		ranking(score[i],rank[i], ST_NUM);
	}
	 
	for(i=0; i<SUBJ_NUM; i++)
	{
		switch(i)
		{
			case 0: printf("\nKOREAN:\n");
					break;
			case 1: printf("\nENGLISH:\n");
					break;
			case 2: printf("\nMATH:\n");
					break;
		}
		for(j=0; j<ST_NUM; j++)
			printf("rank%2d: %c   %d    %c\n",rank[i][j],name[rank_pos[i][j]],
			        stno[rank_pos[i][j]],dept[rank_pos[i][j]]);
	}
	return 0;
}  
void sorting(int *s, int *pos, int num)
{
	int i, j, tmp, tp;
	
	for(i=0;i<num-1; i++)
	  for(j=i+1; j<num; j++)
	  	if(s[i]<s[j])
	  	{
	  		tmp=s[i];		tp=pos[i];	//adjust name position
	  		s[i]=s[j];  	pos[i]=pos[j];
	  		s[j]=tmp;		pos[j]=tp;
		  }
return;
}   
void ranking(int *s, int *r, int num)
{
	int seq=1, same=0, i;   //numbr of real rank addressed the same score & the same score
	for(i=0;i<num-1; i++ )	
	{
		r[i]=seq;
		if(s[i]!=s[i+1]) {
			++same;
			seq+=same;  //add the same number for the next rank
			same=0; 	
		}
		else ++same;
	}
	r[i]=seq; 	//last rank
return;
}
