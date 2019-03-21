#include<stdio.h>
void mergesort(int A[],int n);
void merge(int A[],int a,int B[],int b,int C[]);
int main()
{
	int i,n,A[1000];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter %d elements :",n);
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	mergesort(A,n);
	printf("The sorted array is : \n");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);
	printf("\n");
	return 0;
}
void mergesort(int A[],int n)
{
	int i,j,k,mid;//L[1000],R[1000];
	if(n<2)
	return;
	mid = n/2;
	int L[mid],R[n-mid];
	for(i=0;i<=mid-1;i++)
	L[i] = A[i];
	for(i=mid;i<n;i++)
	R[i-mid] = A[i];
	mergesort(L,mid);
	mergesort(R,(n-mid));
	merge(L,mid,R,n-mid,A);
}
/*

void mergesort(int A[],int n)
{
	int L[1000],R[1000],i,j,k,mid;
	if(n<2)
	return;
	mind = n/2;
	for(i=0;i<mid;i++)
	L[i] = A[i];
	for(i=mid;i<n;i+)
	R[i-mid] = A[i];
	mergesort(L,mid);
	mergesort(R,n-mid);
	merge(L,mid,R,n-mid,A);
}

*/
void merge(int L[],int n1,int R[],int n2,int A[])
{
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{		
		A[k] = L[i];
		++i;
		++k;
		}
		else
		{
		A[k] = R[j];
		++j;
		++k;
		}
	}
	if(i<n1)
	{
		while(i<n1)
		{
			A[k] = L[i];
			++i;
			++k;
		}
	}
	else
	{
		while(j<n2)
		{
			A[k] = R[j];
			++j;
			++k;
		}
	}
}
/*

void merge(int L[],int n1,int R[],int n2,int A[])
{
	int i=0,j=0,k=0;
	if(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			A[k] = L[i];
			++k; ++i;
		}
		else
		{
			A[k] = R[j];
			++k; ++j;
		}
	}
	if(i<n1)
	{
		while(i<n1)
		{
		A[k] = L[i];
		++k; ++i;
		}
	}
	if(j<n2)
	{
		while(j<n2)
		{
		A[k] = R[j];
		++j; ++k;
	}
}		
*/
