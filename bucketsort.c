#include <stdio.h>
#include <stdlib.h>
 
struct bucket 
{
    int count;
    int* value;
};
 
int compareIntegers(const void* first, const void* second)
{
    int x = *((int*)first), y =  *((int*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
 
void bucketSort(int array[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }
    
    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        // now using quicksort to sort the elements of buckets
	// i'll be using bubble sort
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}
 
int main(char *arg[]) {
 
    int array[100] = { 5, -34, 10, 1, -42, 123, 2, 395, 5, 4, 1234, 7 };
    int i = 12,j,k,n;
 
    n=i;
    printf("Before Sorting\n");
    for (j = 0; j<i; j++)
    {
        printf("%d ", array[j]);
    }
 
    bucketSort(array, n); 
    printf("\n After Sorting\n");
    for (k = 0; k<i; k++)
        printf("%d ", array[k]);   
 
 
    return 0;
}

/*#include<stdio.h>
void Bucket_Sort(int array[], int n)
{   
 int i, j;   
 int count[n];  
 for(i=0; i < n; i++)
 {   
  count[i] = 0;   
 }     
 for(i=0; i < n; i++)
 {    
  (count[array[i]])++; 
 }     
 for(i=0,j=0; i < n; i++)
 {   
  for(; count[i]>0;(count[i])--) 
  {       
   array[j++] = i; 
  }  
 }   
}    
int main() 
{ 
 int array[100];   
 int num;   
 int i;  
 printf("Enter How many Numbers : ");    
 scanf("%d",&num);    
 printf("Enter the %d elements to be sorted:\n",num);  
 for(i = 0; i < num; i++ )
 {   
  scanf("%d",&array[i]);  
 }   
 printf("nThe array of elements before sorting : \n"); 
 for (i = 0;i < num;i++) 
 {    
  printf("%d ", array[i]);   
 }    
 printf("nThe array of elements after sorting : \n");  
 Bucket_Sort(array, num);  
 for (i = 0;i < num;i++) 
 {     
  printf("%d ", array[i]);  
 }   
 printf("\n");      
 return 0; 
} 
*/


