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
		printf( "%s�� �߰ߵ��� �ʾ���\n", sub); 
		return 0;
	}
	else
	printf( "%s�� %d �� �߰ߵǾ���\n\n", sub, count);
	
	for(int i=0;i<count; i++)
		printf("%s[%d]����%d��° �߰ߵǾ���\n", "d",loc[i],i+1);
		
	return 0;
}


