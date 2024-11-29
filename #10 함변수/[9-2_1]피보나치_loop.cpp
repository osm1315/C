#include <stdio.h>

int main(void)
{
	int i, n;
	
	scanf("%d",&n);
	int f_value[n]={1,1};
	
	for(i=2; i<n; i++)
	 	f_value[i]=f_value[i-1]+f_value[i-2];
	for(i=0; i<n; i++)
		printf("%3d)%d", i+1, f_value[i]);
return 0;
}
