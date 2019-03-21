#include<stdio.h>
int main()
{
	int i,j,n,A[1000],temp;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	for(i=1;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	printf("The sorted array is: \n");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
	printf("\n");
	return 0;
}
