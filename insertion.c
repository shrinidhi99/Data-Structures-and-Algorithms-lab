#include<stdio.h>
int main()
{
	int i,j,hole,n,A[1000],value;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	for(i=1;i<n;i++)
	{
		hole = i;
		value = A[i];//A[i] in the algorithm
		while(hole>0 && A[hole-1]>value)
		{
			A[hole] = A[hole-1];
			hole = hole - 1;
		}
		A[hole] = value;//A[i+1] in the algorithm
	}
	printf("The sorted array is: \n");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
	printf("\n");
	return 0;
}
/*
logic

for(i=1;i<n;i++)
{
	hole = i;
	value = A[i];
	while(hole>0 && A[hole-1] > value)
	{
		A[hole] = A[hole-1];
		hole = hole - 1
	}
	A[hole] = value;
	}
}

*/
