#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,temp,min,A[1000],n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<n-1;i++)
	{
		min=i;//pos = i;
		for(j=i+1;j<n;j++)
		{
			if(A[min]>A[j])
			{
				min = j;
			}
		}
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;

	}
	printf("The sorted array is: \n");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
	printf("\n");
	return 0;
}
