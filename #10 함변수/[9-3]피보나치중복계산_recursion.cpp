#include <stdio.h>

int fibo(int , int *, int *, int *);
int main(void)
{
	int i, n;
	
	scanf("%d",&n);
	int f_value[n], f_cal[n]={0,}, total=0;  	//Variable Length Array

	fibo(n, f_value, f_cal, &total);
	for(i=0; i<n; i++)
		printf("%3d(#%d)\n",f_value[i],f_cal[i]);
	printf("Total_cal: #%d",total);
return 0;
}
int fibo(int n, int *fv, int *fc, int *cal)
{   
	fv[n-1]=(n==1 || n==2)? 1: fibo(n-1,fv,fc,cal)+fibo(n-2,fv,fc,cal);
	fc[n-1]++;
	(*cal)++;
return fv[n-1];
}
