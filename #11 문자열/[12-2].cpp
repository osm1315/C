#include <stdio.h>
#include <string.h>
#define LINE 50
int main(void)
{
	char d[LINE], sub[LINE];	
	char *q, *again=d, *dend;
	int count=0, loc[LINE]={0}; //sublen;
	
	printf("string:\n");
	gets(d); //tset:  ab		baba   ab  //ab  ssabba  	   ab//
	printf("substring:\n");
	gets(sub);
	dend=d+strlen(d);
	//sublen=strlen(sub);
	
	do
	{
	q = strstr(again, sub);
	if ( q != NULL )
	   {	loc[count]=(int) (q-d);
	        count++;
	   		again=++q;//again=q+sublen;
	   }
	else break;
	} while(dend>again);
	
	if(!count)
		{
		printf( "%s가 발견되지 않았음\n", sub); 
		return 0;
	}
	else
	printf( "%s가 %d 번 발견되었음\n\n", sub, count);
	
	for(int i=0;i<count; i++)
		printf("%s[%d]에서%d번째 발견되었음\n", "d",loc[i],i+1);
		
	return 0;
}


