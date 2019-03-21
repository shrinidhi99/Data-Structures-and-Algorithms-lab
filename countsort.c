#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
	if(a>b)
	return a;
	else 
	return b;
}
void main()
{
	int A[1000],B[1000],output[1000],i,j=0,k,n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter %d elements :\n",n);	
	j=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		j = max(j,A[i]);
	}
	printf("%d\n",j);
	for(i=0;i<=j;i++)
	B[i] = 0;
	for(i=0;i<n;i++)
	B[A[i]] = B[A[i]]+1;
	for(k=1;k<=j;k++)
	{
		B[k] = B[k] + B[k-1];
	}
	for (i = 0; A[i]; ++i) 
    	{ 
        	output[B[A[i]]-1] = A[i]; // C[B[A[i]]-1] = A[i] 
        	--B[A[i]]; 
    	}
	printf("Sorted array is : ");
	for(i=0;i<n;i++)
	printf("%d ",output[i]);//C[i]
}

