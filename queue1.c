#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node* head = NULL;
void enqueue(int x,int n);
void dequeue();
void search(int x);
void display();
void main()
{
	int i=0,ch;
	for(;;)
	{
	printf("Enter\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			int x,n;
			printf("Enter an element to be inserted: ");
			scanf("%d",&x);
			enqueue(x,++i);
			display();
			break;
		}
		case 2:
		{
			if(i==0)
			{
				printf("The queue is empty!\n");
				display();
			}
			else
			{
				dequeue();
				--i;
				display();
			}
			break;
		}
		case 3:
		{
			if(i==0)
			{
				printf("The queue is empty!\n");
				display();
			}
			else
			{
				int x;
				printf("Enter the element to be searched in the queue: ");
				scanf("%d",&x);
				search(x);
				display();
			}
			break;
		}
		case 4:
		{
			display();
			break;
		}
		case 5:
		{
			exit(0);
		}
		default:
		printf("Invalid choice\n");
	}
	}
}	
void enqueue(int x,int n)
{
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
	temp1->data = x;
	temp1->next = NULL;
	int i;
	if(n==1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	struct Node* temp2 = head;
	for(i=0;i<n-2;i++) 
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void dequeue()
{
	struct Node* temp = head;
		head = temp->next;
		free(temp);
		return;
}
void search(int x)
{
	int flag = 0;
	struct Node* temp = head;
	while(temp!=NULL)
	{
		if(temp->data == x)
		{
			printf("%d has been found in the queue.\n",x);
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if(flag==0)
	printf("%d was not found in the queue.\n",x);
}
void display()
{
	struct Node* temp = head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");	
}
