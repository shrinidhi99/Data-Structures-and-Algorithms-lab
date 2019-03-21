#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void print(long int A[],long int n)
{
	long int i=0;
	printf("Note: '0' indicates that there is nothing stored at that place.\n");
	for(i=0;i<n;i++)
	{
		if(i==0)
		printf(" Root: %ld",A[i]);
		printf(" Left child: %ld",(2*i+1));
		printf(" Right child: %ld",(2*i+2));
	}
}
void main()
{
	long int A[1000],h,n=1,i,j,k,e;
	printf("Enter the height of the tree: ");
	scanf("%ld",&h);
	for(i=1;i<=(h+1);i++)	
		n = n+2;
	n = n - 1;
	for(i=0;i<n;i++)
	A[i] = 0;
	for(i=0;i<n;i++)
	{	
		printf("Enter\n1.Insert element\n2.Terminate\n");
		scanf("%ld",&j);
		switch(j)
		{
			case 1:
			{
				printf("Enter\n1.Left Child\n2.Right child");
				scanf("%ld %ld",&k,&e);
				if(k==1)
				A[2*i+1] = e;
				if(k==2)
				A[2*i+2] = e;
				
				break;
			}			
			case 2:
			{
				print(A,n);
				exit(0);
			}
			default:
			printf("Invalid Choice\n");
		}
	}
}

