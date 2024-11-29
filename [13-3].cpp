#include <stdio.h>
#include <string.h>

#define STNUM 5
#define MAJOR 2
#define NAME 4

typedef struct exam {
	char no[MAJOR+NAME+1];
	char name[NAME+1];
	char major[MAJOR+1];
	int jumsu;
	int rank;
} APPLY;

int passfail(int);
void assign(APPLY [], int);
void ranking(APPLY [], int);
void sorting(APPLY [], int);
void display(APPLY [], int);

int main(void)
{ 
APPLY app[STNUM], in;
int pass_count=0, tmp=0;

printf("name   major   jumsu\n");
for(int i=0; i<STNUM; i++)
{ scanf("%s %s %d", in.name, in.major, &in.jumsu);
  if (passfail(in.jumsu))    //determin whether pass or not
	   app[pass_count++]=in;
}
if (pass_count) assign(app,pass_count);  // assign passed student number
else {
	printf("ALL FAILED\n"); return 0; }

ranking(app, pass_count);
sorting(app, pass_count);
display(app, pass_count);

return 0;
}

//////////////////////////////
int passfail(int score)
{
if (score>=60) return 1;
else return 0;
}
//////////////////////////
void assign(APPLY info[], int count)
{
	char temp[2];
	for(int i=0; i<count; i++)
	{
		strcpy(info[i].no,info[i].major);
		strncpy[temp,info[i].name];
		strcat(info[i].no,temp);
	}
}
///////////////////////////
void ranking(APPLY info [], int count)
{ 
int i, j, rank=1, same=0;
APPLY tmp;

for(i=0; i<count-1; i++)   ///sorting according to score
  for(j=i+1; j<count; j++)
  	if(info[i].jumsu<info[j].jumsu)
  	 {
  	 	tmp=info[j];
  	 	info[j]=info[i];
  	 	info[i]=tmp;
  	 }
for(i=0; i<count; i++)
  info[i].rank=i+1;

return;
}
/////////////////////////
void sorting(APPLY info[], int count)
{
	APPLY tmp;
	int i, j;
	
	for(i=0; i<count-1; i++)   ///sorting according to st. no
      for(j=i+1; j<count; j++)
      	if(strcmp(info[i].no,info[j].no)>0)
      	{
      		tmp=info[j];
  	 		info[j]=info[i];
  	 		info[i]=tmp;
		  }
return;
}
/////////////////////////////
void display(APPLY info[], int count)
{
 int major_count=1;
 
for(int i=0; i<count; i++)
	printf("%s     %s     %s     %d    %d\n\n", info[i].no, info[i].name, info[i].major, info[i].jumsu, info[i].rank);

for(int i=0; i<count; i++)
	if(!(i+1==count))
	   if(!strcmp(info[i].major, info[i+1].major))
	       major_count++;
	   else 
	    {
		   printf("%s: %d\n", info[i].major, major_count);
		   major_count=1;
	    }
	else     //last member
	   printf("%s: %d\n", info[i].major, major_count);
return ;
}
