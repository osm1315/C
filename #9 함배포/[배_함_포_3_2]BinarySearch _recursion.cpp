#include <stdio.h>
#define NUM 5

void sorting(int (*score)[2], char *name, int *mapping, int num);
void binary_search(char tn, char *name, int start, int last, int *index);

int main(void)
{
	int i, n, index=-1, score[NUM][2];	//col: 0(score) 1(grade), index=-1:NOT found
	char name[NUM], t_name;
	int start=0,last=NUM-1;
	int mapping[NUM];	//FOR mapping between name[] and score[][] without exchanging all elements in score[][]
	
	printf("input name(1), 1 score:\n");
	for(i=0; i<NUM; i++)
	{
		scanf("%c %d",&name[i],&score[i][0]);	//format: K 88 return
		scanf("%c",&t_name);	//discard return char.
	}
	sorting(score, name, mapping, NUM);	//SORT By score[][] & name[]
	printf("Student Information\n");	//Order BY NAME
	for(i=0; i<NUM; i++)
		printf("%c: %d  %d\n", name[i],score[mapping[i]][0],score[mapping[i]][1]);
		
	printf("Input name to find:\n");
	scanf("%c",&t_name);
	
	binary_search(t_name, name, start, last, &index);	//index means matched position if exists
	
	if(index==-1) { printf("NO NAME FOUND");
					return 0;
				}
	printf("\n%c: %d  %d",name[index],score[mapping[index]][0],score[mapping[index]][1]);	
return 0;	
}
void sorting(int (*score)[2], char *name, int *mapping, int num)
{	int i, j, k, tmp, seq, same; 
	char tn;
	
	for(i=0; i<num-1; i++)	
	{
		for(j=i+1; j<num; j++)
			if( score[i][0]<score[j][0])
			{	
				tmp=score[i][0];
				score[i][0]=score[j][0];
				score[j][0]=tmp;
				tn=name[i];	   //adjust name[]
				name[i]=name[j];	
				name[j]=tn;
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
			if(name[i]>name[j])
			{	tn=name[i];
				name[i]=name[j];
				name[j]=tn;
				tmp=mapping[i];	   //adjust the original position in sorted score[][]
				mapping[i]=mapping[j];	
				mapping[j]=tmp;
			}
return;		
}
void binary_search(char tn, char *name, int start, int last, int *index)
{	int mid;
	if(start<=last)
	{   mid=(start+last)/2;
		if(tn<name[mid]) binary_search(tn, name, start, mid-1, index);
		else if(tn>name[mid]) binary_search(tn, name, mid+1, last, index);
		else *index=mid;     //FOUND
	}
return;    //NOT Found
}
