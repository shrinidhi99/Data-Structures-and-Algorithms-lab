#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node* head = NULL;
void insert(int x,int n);
void delete(int n);
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
			printf("Enter an element to be inserted and its position : ");
			scanf("%d %d",&x,&n);
			insert(x,n);
			++i;
			display();
			break;
		}
		case 2:
		{
			if(i==0)
			{
				printf("The linked list is empty!\n");
				display();
			}
			else
			{
				printf("Enter the position of the element to be deleted: ");
				int n;
				scanf("%d",&n);
				delete(n);
				--i;
				display();
			}
			break;
		}
		case 3:
		{
			if(i==0)
			{
				printf("The linked list is empty!\n");
				display();
			}
			else
			{
				int x;
				printf("Enter the element to be searched in the linked list: ");
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
void insert(int x,int n)
{
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
	temp1->data = x;
	temp1->next = NULL;
	int i;
	if(n==1)
	{
		temp1->next = head;//temp->next = NULL
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
void delete(int n)
{
	int i;
	struct Node* temp = head;
	if(n==1)
	{
		head = temp->next;
		free(temp);
		return;
	}
	for(i=0;i<n-2;i++)
	{
		temp = temp->next;
	}
	struct Node* temp3 = temp->next;
	temp->next = temp3->next;
	free(temp3);
}
void search(int x)
{
	int flag = 0;
	struct Node* temp = head;
	while(temp!=NULL)
	{
		if(temp->data == x)
		{
			printf("%d has been found in the linked list.\n",x);
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if(flag==0)
	printf("%d was not found in the linked list.\n",x);
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
