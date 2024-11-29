#include <stdio.h>

int fibo(int n, int *fv, int *cal);
int main(void)
{
	int i, n;
	
	scanf("%d",&n);
	int f_value[n], cal_val[n]={0};  	//Variable Length Array
		//cal_val[] is declared to avoid duplicate calculation of fibo. value; 0:need to calculate
	
	fibo(n, f_value, cal_val);
	for(i=0; i<n; i++)
		printf("%3d)%d", i+1, f_value[i]);
return 0;
}
int fibo(int n, int *fv, int *cal)
{ 
  	if(!cal[n-1])	//need to calculate
	{
		fv[n-1]=(n==1 || n==2)? 1: fibo(n-1,fv,cal)+fibo(n-2,fv,cal);
		cal[n-1]=1; 	//tagging as calculated
	}
return fv[n-1];
}
