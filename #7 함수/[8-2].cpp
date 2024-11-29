#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10
void sorting(int [], int);
int main(void)
{
	int i, j, k, tmp, num[NUM]={0},even[NUM], odd[NUM];
	int oend=0, eend=0, oindex=0, eindex=0, index=0;
	char found;
	
	srand((unsigned int)time(NULL));
		
	for(i=0;i<NUM;i++)
		do
		{ 
		  num[i]=rand()%100+1;
		  for(j=0; j<i; j++)
		  	if(num[i]!=num[j]) continue;
		  	else 
			  {
			  	found='Y';
			  	break;
			  }
		  if(i==j) 	found='N';  //distinct random number
		} while(found=='Y');

	for(i=0;i<NUM;i++)	printf("%4d", num[i]);
	for(i=0;i<NUM;i++)	
		if(num[i]%2!=0)
			odd[oend++]=num[i];
		else even[eend++]=num[i];
	printf("\n^^^^%d %d\n",oend,eend);
	sorting(odd,oend);  //oend and eend are number of odd and even number, respectively
	sorting(even,eend);
	
	while(oindex<=oend-1 && eindex<=(eend-1))	//both are in progress
		if(odd[oindex]>even[eindex])
			num[index++]=even[eindex++];
		else
			num[index++]=odd[oindex++];
	
	if(!(oindex<oend))	//odd is finished, so copy even
		for(i=eindex;i<eend;i++)
			num[index++]=even[eindex++];
	else if(!(eindex<eend))    //even is finished, so copy odd
		for(i=oindex;i<oend;i++)
			num[index++]=odd[oindex++];
			
	printf("\nODD:\n");
	for(i=0; i<oend; i++)		
		printf("%4d",odd[i]);
	printf("\nEVEN:\n");
	for(i=0; i<eend; i++)		
		printf("%4d",even[i]);	
	printf("\nMERGE:\n");
	for(i=0; i<NUM; i++)		
		printf("%4d",num[i]);	
return 0;				    
}
void sorting(int num[], int n)	
{
	int i, j, tmp;
	for(i=0;i<n-1;i++)	
	 for(j=i+1;j<n;j++)	 
	 	if(num[i]>num[j])
	 	{
	 		tmp=num[i];		
	 		num[i]=num[j];	
	 		num[j]=tmp;	
	 	}
return ;
}
