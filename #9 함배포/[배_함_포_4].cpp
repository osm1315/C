#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 20
#define G_NUM 10

int main(void)
{
	int i, j, k, tmp, count[G_NUM]={0,};
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
	
	for(i=0;i<G_NUM-1;i++)		//sorting by both number & group name if necessary
	 for(j=i+1;j<G_NUM;j++)	 
	 	if(count[i]<count[j])
	 	{
	 		tmp=count[i];		tmp_g=group[i];
	 		count[i]=count[j];	group[i]=group[j];
	 		count[j]=tmp;		group[j]=tmp_g;
	 	}
	 	else if(count[i]==count[j] && group[i]>group[j]) //same number, so sort by name
	 	{   tmp_g=group[i];
	 		group[i]=group[j];
	 		group[j]=tmp_g;
		 }
	printf("\n<RESULT>\n")	;	
	for(i=0;i<G_NUM; i++)
	 printf("GROUP %c:%d\n", group[i],count[i]);
return 0;				    
}

