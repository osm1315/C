#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 20
void sorting(int [],int);
int binary_search(int [], int , int , int, int *);
//void binary_search(int [], int , int , int, int *, int *);
int main(void)
{
	int i,j, n, index, target, compare=0, pool[NUM]={0};
	char found;
	
	srand((unsigned int)time(NULL));	
	for(i=0;i<NUM;i++)		//exclude duplicate number
		do
		{ 
		  pool[i]=rand()%30+71;
		  for(j=0; j<i; j++)
		  	if(pool[i]!=pool[j]) continue;
		  	else 
			  {
			  	found='Y';
			  	break;
			  }
		  if(i==j) 	found='N';
		} while(found=='Y');
	
	
	sorting(pool, NUM);
	for(i=0;i<NUM;i++)	
		printf("%4d",pool[i]);
		
	printf("\nInput numner(71~100)) to find:\n");
	scanf("%d",&target);
	
	index=binary_search(pool, target, 0, NUM-1, &compare);
	//binary_search(pool, target, 0, NUM-1, &compare,&index);
	if(index==-1) 
		printf("NO NUMBER FOUND after %d comparison\n",compare);	//index:-1 NOT FOUND
	else
		printf("pool[%d]=%d  comparison:%d",index, pool[index], compare);	
return 0;	
}

void sorting(int pool[],int num)   //descending order
{	int i, j, tmp; 
	
	for(i=0; i<num-1; i++)	
		for(j=i+1; j<num; j++)
			if( pool[i]<pool[j])
			{	
				tmp=pool[i];
				pool[i]=pool[j];
				pool[j]=tmp;
			}
return;
}
	
int binary_search(int pool[], int target, int start, int last, int *count)
//void binary_search(int pool[], int target, int start, int last, int *count, int *index)
{	int mid, index=-1;

	if(start<=last)
	{   mid=(start+last)/2;
		(*count)++;
		if(target>pool[mid]) 	index=binary_search(pool, target, start, mid-1, count);
		else if(target<pool[mid]) 	index=binary_search(pool, target, mid+1, last, count);
		else index=mid;    //FOUND      
	}
return index;    //NOT Found				
}
