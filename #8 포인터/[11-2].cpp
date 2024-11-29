#include <stdio.h>
//#include <stdbool.h>   /* C99 */
#define LINE 3
void line_scan(int *, float *);
void sorting(int num[], int line_no[], float *,int n);
int main(void)
{
  int i, total_word=0, line_word[LINE]={0,}, line_no[LINE];
  float total_leng=0, line_avg_leng[LINE]={0.,};
  
    for(i=0; i<LINE; i++)
    {
  		line_no[i]=i+1;
		line_scan(&line_word[i],&line_avg_leng[i]);
  		total_word+=line_word[i];
  		total_leng+=line_avg_leng[i];
  	}
    
	sorting(line_word,line_no,line_avg_leng,LINE);
	
	for(i=0; i<LINE; i++)
  		printf("Line%d=> words: %d,  avg: %.2f\n",line_no[i], line_word[i], line_avg_leng[i]);
  	printf("\n\nTotal words: %d,  Total avg: %.2f\n",total_word, total_leng/LINE) ;
return 0;
}
  	
void line_scan(int *words, float *avg)
{
  char ch, succ='Y';   //successive blank or tab    //cf. bool succ = false;
  int letters=0;
  printf("Input one line sentence:");
  while ((ch = getchar()) != '\n')
    if (ch!=' '&& ch!='\t')     /* a letter */
    {
	  letters++;
      succ='N';
  	}
    else if(succ!='Y')  //The first ' ' or '\t'
		{ (*words)++;
	  	  succ='Y';
	    }
  if(succ=='N') 	//no ' ' and '\t' before '\n'
  	(*words)++; 	//the last word
  if ((*words)>0)
    (*avg)= (float)letters/(*words);
  //return;    return 0; 
}

void sorting(int num[], int line_no[], float line_avg_leng[], int n)	
{
	int i, j, tmp;
	float temp;
	for(i=0;i<n-1;i++)	
	 for(j=i+1;j<n;j++)	 
	 	if(num[i]<num[j])
	 	{
	 		tmp=num[i];		
	 		num[i]=num[j];	
	 		num[j]=tmp;	
	 		tmp=line_no[i];		
	 		line_no[i]=line_no[j];	
	 		line_no[j]=tmp;
	 		temp=*(line_avg_leng+i);
	 		*(line_avg_leng+i)=*(line_avg_leng+j);
	 		*(line_avg_leng+j)=temp;
	 	}
return;
}
