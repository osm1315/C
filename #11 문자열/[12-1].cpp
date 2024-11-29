#include <stdio.h>
#include <string.h>
#define NUM 5
#define SIZE 10

void sorting(int (*score)[2], char (*name)[SIZE],int *mapping, int num);
int binary_search(char *tn, char (*name)[SIZE], int start, int last);

int main(void)
{
	int i, n, index, score[NUM][2];	//col: 0(score) 1(grade)
	char name[NUM][SIZE], tname[SIZE], ch;
	int start=0,last=NUM-1;
	int mapping[NUM];	//FOR mapping between name[] and score[][] without exchanging all elements in score[][]
	
	printf("input name with blank, 1 score:\n");
	for(i=0; i<NUM; i++)
	{
		printf("Name with blank\n");
		gets(name[i]);
		printf("Score\n");
		scanf("%d",&score[i][0]);
		ch=getchar(); 
	}
	
	sorting(score, name, mapping, NUM);	//SORT By score[][] & name[]
	
	printf("Student Information\n");	//Order BY NAME
	
//	for(i=0; i<NUM; i++) puts(name[i]);
	for(i=0; i<NUM; i++)
	{
		puts(name[i]);
		printf(": %d  %d\n",score[mapping[i]][0],score[mapping[i]][1]);
    }
		
	printf("Input name to find:\n");
	gets(tname);
	
	index=binary_search(tname, name, start, last);	//index means matched position if exists
	
	if(index==-1) { printf("NO NAME FOUND");	//index=-1:NOT found
					return 0;
				}
	puts(name[index]);
	printf("\n: %d  %d",score[mapping[index]][0],score[mapping[index]][1]);	
return 0;	
}
void sorting(int (*score)[2], char name[][SIZE], int *mapping, int num)
{	int i, j, k, tmp, seq, same; 
	char tn[SIZE];
	
	for(i=0; i<num-1; i++)	
	{
		for(j=i+1; j<num; j++)
			if( score[i][0]<score[j][0])
			{	
				tmp=score[i][0];
				score[i][0]=score[j][0];
				score[j][0]=tmp;
				strcpy(tn,name[i]);
				strcpy(name[i],name[j]);	   //adjust name[]
				strcpy(name[j],tn);
			}
	}
	
		//Ranking
    seq=1;
	same=0;   //numbr of the same score
	for(i=0;i<num;i++ )		//address the same rank
	{
		score[i][1]=seq;
		if(score[i][0]!=score[i+1][0]) {
			++same;
			seq+=same;  //add the same number for the next rank
			same=0; 	
		}
		else ++same;
	}
	score[i][1]=seq; 	//last rank
	
	for(i=0; i<NUM; i++)
		mapping[i]=i;	//each student position in sorted score[][]
		
	for(i=0; i<num-1; i++)	//sort by name
		for(j=i+1; j<num; j++)
			if(strcmp(name[i],name[j])>0)
			{	strcpy(tn,name[i]);
				strcpy(name[i],name[j]);	
				strcpy(name[j],tn);
				tmp=mapping[i];	   //adjust the original position in sorted score[][]
				mapping[i]=mapping[j];	
				mapping[j]=tmp;
			}
return;		
}
int binary_search(char *tn, char (*name)[SIZE], int start, int last)
{	int mid;
	static int index=-1; 

	if(start<=last)
	{   mid=(start+last)/2;
		if(strcmp(tn,name[mid])<0) binary_search(tn, name, start, mid-1);
		else if(strcmp(tn,name[mid])>0) binary_search(tn, name, mid+1, last);
		else index=mid;     //FOUND
	}
return index;    //NOT Found
}
