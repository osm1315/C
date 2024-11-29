#include <stdio.h>

int fibo(int n, int *fv);
int main(void)
{
	int i, n;
	
	scanf("%d",&n);
	int f_value[n];  	//Variable Length Array

	fibo(n, f_value);
	for(i=0; i<n; i++)
		printf("%3d)%d", i+1, f_value[i]);
return 0;
}
int fibo(int n, int *fv)
{ 
	if(n==1|| n==2) return (fv[n-1]=1);
	else return (fv[n-1]=fibo(n-1,fv)+fibo(n-2,fv));
}
