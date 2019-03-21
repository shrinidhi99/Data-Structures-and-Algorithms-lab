#include<stdio.h>
void quicksort(int A[],int start,int end);
int partition(int A[],int start,int end);
void main()
{
	int i,A[1000],n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements: ",n);
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	quicksort(A,0,n-1);
	printf("The sorted array is: \n");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
	printf("\n");
}
int partition(int A[],int start,int end)
{
	int i,temp,pivot,pIndex;
	pivot = A[end];
	pIndex = start;
	for(i=start;i<end;i++)
	{
		if(A[i]<pivot)
		{
			temp = A[i];
			A[i] = A[pIndex];
			A[pIndex] = temp;
			++pIndex;
		}
	}
	temp = A[end];
	A[end] = A[pIndex];
	A[pIndex] = temp;
	return pIndex;
}
void quicksort(int A[],int start,int end)
{
	int pIndex;
	if(start<end)
	{
		pIndex = partition(A,start,end);
		quicksort(A,start,pIndex-1);
		quicksort(A,pIndex+1,end);
	}
}
/*

int partition(int A[],int start,int end)
{
	int pindex,pivot,i,j,k;	
	pindex  = start;
	pivot = A[end];
	for(i=start;i<end;i++)
	{
		if(A[i]<pivot)
		{
			temp = A[i];
			A[i] = A[pindex];
			A[pindex] =  temp;
			++pindex;		
		}
	}
	temp = A[end];
	A[end] = A[pindex];
	A[pindex]  = temp;
	return pindex;
}
void qsort(int A[],int start,int end)
{
	if(start<end)
	{
		pindex = partition(A,start,end);
		qsort(A,start,pindex-1);
		qsort(A,pindex,end);
	}
}	
*/
