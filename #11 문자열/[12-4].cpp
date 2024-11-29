#include <stdio.h>
#include <string.h>
#define NUM 10
#define LENG 10
int main(void)
{
	char dname[NUM][LENG], sname[NUM][LENG], str_sno[NUM][LENG];
	char tmp[LENG];
	int i, j, index;
	
	printf("Input dname, sname\n");
	for(i=0; i<NUM; i++)
		scanf("%s %s", dname[i], sname[i]);
	
	for(i=0; i<NUM-1; i++)		//sort by std. name
		for(j=i+1; j<NUM; j++)
			if(strcmp(sname[i],sname[j])>0)
			{
				strcpy(tmp,dname[j]); 
				strcpy(dname[j],dname[i]);
				strcpy(dname[i],tmp);
				strcpy(tmp,sname[j]); 
				strcpy(sname[j],sname[i]);
				strcpy(sname[i],tmp);
			}

	index=1;
	char same='N';
	int d1, d2;
	char c1,c2;
	for(i=0;i<NUM-1; i++ )		//deal with the same name
	{
		d1=index/10;
		c1=d1+'0';
	    d2=index-d1*10;
	    c2=d2+'0';
	    tmp[0]=c1; 	tmp[1]=c2;	tmp[2]='\0';	//string digit
	   
		if(!strcmp(sname[i],sname[i+1])) //same name
		{
			strncpy(str_sno[i],dname[i],2);
			str_sno[i][2]='\0';
			strcat(str_sno[i],tmp);
			same='Y';
		}
		else if(same=='N')
		{
			strcpy(str_sno[i],tmp);	
			++index;
		}
		else 		//the last one that is same as previous one
		{
			strncpy(str_sno[i],dname[i],2);
			str_sno[i][2]='\0';
			strcat(str_sno[i],tmp);
			same='N';
			++index;
		}
	}//for
		if(same=='Y')	//process the last name
		{
			strncpy(str_sno[i],dname[i],2);
			str_sno[i][2]='\0';
			strcat(str_sno[i],tmp);
		}
		else
			{
				d1=index/10;		//new next number
				c1=d1+'0';
	    		d2=index-d1*10;
	    		c2=d2+'0';
	    		tmp[0]=c1; 	tmp[1]=c2;	tmp[2]='\0';	//string digit
				strcpy(str_sno[i],tmp);	
			}
	
		for(i=0; i<NUM-1; i++)	//sort by st. no
			for(j=i+1; j<NUM; j++)
				if(strcmp(str_sno[i],str_sno[j])>0)
				{
					strcpy(tmp,str_sno[j]); 
					strcpy(str_sno[j],str_sno[i]);
					strcpy(str_sno[i],tmp);
					strcpy(tmp,dname[j]); 
					strcpy(dname[j],dname[i]);
					strcpy(dname[i],tmp);
					strcpy(tmp,sname[j]); 
					strcpy(sname[j],sname[i]);
					strcpy(sname[i],tmp);
				}
	printf("===========================\n");
	for(i=0; i<NUM; i++)
		printf("%s: %s  %s\n", str_sno[i],sname[i], dname[i]);
return 0;
}
		
