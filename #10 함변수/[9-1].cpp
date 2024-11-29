#include <stdio.h>
void avg_ascii(char, float*, int *);
int main(void)
{
	int i=0, count=0;
	float avg;
	char alpha, word[21];
	printf("input a word:\n");
		do
		{
			scanf("%c",&alpha);
			word[i++]=alpha;
			avg_ascii(alpha,&avg,&count);
		} while(alpha>='A'&&alpha<='Z');
		word[--i]='\0';
		printf("%s:  Length: %d  Avg_ASCII=%.2f",word,count,avg);
return 0;
}

void avg_ascii(char ch, float *avg, int *leng)
{
	//static int count=0, sum=0;
	static int sum=0;
	if(ch>='A'&&ch<='Z')
	{
		sum+=ch;
		++(*leng);
		//++count;   
	}
	else	//end of a word
	{
		//*avg=(float)sum/count;
		*avg=(float)sum/(*leng);
		//*leng=count;	
	}
return;
}
