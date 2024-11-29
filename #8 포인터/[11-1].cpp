#include <stdio.h>
#define NUM 20
void add_sub(int,int,int*,int*);
void swap(int*,int*);

int main(void)
{
	int m, n, sum, diff;
	
	printf("Input 2 numbers:\n");
	scanf("%d%d",&m,&n);

	add_sub(m,n,&sum,&diff);
	printf("Before: sum=%d, diff=%d\n",sum,diff);
	swap(&m,&n);
	add_sub(m,n,&sum,&diff);
	printf("After: sum=%d, diff=%d\n",sum,diff);
	
return 0;
}

void add_sub(int m, int n, int *sum, int *diff)
{
	*sum=m+n;
	*diff=m-n;
return;
}

void swap(int *m,int *n)
{
	int tmp;
	tmp=*m;
	*m=*n;
	*n=tmp;
return;
}
