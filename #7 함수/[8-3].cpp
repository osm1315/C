#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 20
#define G_NUM 10
void sorting(char *, int, int);

int main(void)
{
	int i, j, k, tmp, count[G_NUM]={0,}, max_same=1, min_same=1;
	char group[G_NUM], tmp_g;	//group[0], count[0]='A'....group[9], count[9]='J'
	
	for(i=0;i<NUM;i++)	//initialize each group name (A ~ J)
		group[i]='A'+i; 
		
	srand((unsigned int)time(NULL));
		
	for(i=0;i<NUM;i++)
	{
		k=rand()%100;
		printf("%4d",k);
		count[k/10]++;  //increase the corresponding group
	}
	
	for(i=0;i<G_NUM-1;i++)		//sorting in descending order
	 for(j=i+1;j<G_NUM;j++)	 
	 	if(count[i]<count[j])
	 	{
	 		tmp=count[i];		tmp_g=group[i];
	 		count[i]=count[j];	group[i]=group[j];
	 		count[j]=tmp;		group[j]=tmp_g;
	 	}
	 
	for(i=0;i<G_NUM-1; i++ )		//count the same MAX member
		if(count[i]==count[i+1])
			++max_same;
		else break;
			
	sorting(group,0,max_same);   //start from [0] in case of MAX
	
	if(max_same!=G_NUM)  //exist at least 1 group with min member
	{
		for(i=G_NUM-1;i<0; i-- )
			if(count[i]==count[i-1])	//count the same MIN member
				++min_same;
			else break;
		sorting(group,G_NUM-min_same, min_same); //start from the first position of MIN
	} 
	else min_same=max_same;	//all groups are same
	for(i=G_NUM-min_same;i<G_NUM; i++ )
	 	printf("\nMIN_GROUP %c:%d", group[i],count[i]);
	for(i=0;i<max_same; i++ )
	 printf("\nMAX_GROUP %c:%d", group[i],count[i]);
return 0;				    
}

void sorting(char *group, int start, int same)
{ int i, j;
  char tmp;

for(i=start;i<start+same-1;i++)		//cf.i< G_NUM-1
	 for(j=i+1;j<same;j++)	 
	 	if(group[i]>group[j])
	 	{
	 		tmp=group[i];
	 		group[i]=group[j];
	 		group[j]=tmp;
	 	}
return;
}
