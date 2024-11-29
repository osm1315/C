#include <stdio.h>
#define NUM 5

void sorting(int (*score)[2], char name[], int);
int binary_search(char tn, char *name, int num) ;

int main(void)
{
	int i, n, index, score[NUM][2];	//col: 0(score) 1(rank)
	char name[NUM], t_name;
	printf("inpt name(1 char) & 1 score\n");
	for(i=0; i<NUM; i++)
	{
		scanf("%c %d",&name[i],&score[i][0]);	//format: K 88 return
		scanf("%c",&t_name);     //discard return char.
	}
	sorting(score, name, NUM);  //sorting by score&name
	printf("Student Information\n");	//Order BY NAME
	for(i=0; i<NUM; i++)
		printf("%c: %d  %d\n", name[i],score[i][0], score[i][1]);
		
	printf("Input name to find:\n");
	scanf("%c",&t_name);
	
	index=binary_search(t_name, name, NUM);
	
	if(index==-1) { printf("NO NAME");	//index:-1 NOT FOUND
					return 0;
				}
	printf("%c: %d  %d",name[index],score[index][0],score[index][1]);	
return 0;	
}
void sorting(int (*score)[2], char *name, int num)
{	int i, j, k, tmp, seq, same; 
	char tn;
	
	for(i=0; i<num-1; i++)	//sort by score
	{
		for(j=i+1; j<num; j++)
			if( score[i][0]<score[j][0])
			{	tn=name[i];
				name[i]=name[j];
				name[j]=tn;
				tmp=score[i][0];
				score[i][0]=score[j][0];
				score[j][0]=tmp;
			}
	}
	
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
	score[i][1]=seq; 	//last rank */
	
	for(i=0; i<num-1; i++)	//sort by name
		for(j=i+1; j<num; j++)
			if( name[i]>name[j])
			{	tn=name[i];
				name[i]=name[j];
				name[j]=tn;
				for(k=0; k<2; k++)
				{
					tmp=score[i][k];
					score[i][k]=score[j][k];
					score[j][k]=tmp;
				}
			}
return;		
}
int binary_search(char tn, char *name, int num)
{	int start=0,last=num-1, mid;

	while(start<=last)
	{   mid=(start+last)/2;
		if(tn<name[mid]) last=mid-1;
		else if(tn>name[mid]) start=mid+1;
		else return mid;     //FOUND
	}
return -1;    //NOT Found
}

