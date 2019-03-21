#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
struct Node* GetNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
void InsertAtHead(int x)
{
	struct Node* newNode = GetNewNode(x);
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}
/*void Insert(int x,int n)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data = x;
	if(head == NULL)
	{
		temp->prev = head;
		temp->next = NULL;
		head = temp;
	}
	int i;
	struct Node* temp2;
	//temp2 = temp->next;
	for(i=0;i<n-2;i++)
	{
		temp2->prev = temp->prev->next;
		temp2->next = NULL;
		temp = temp2;
	}
}*/
	
void Print()
{
	struct Node* temp = head;
	printf("Forward: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void ReversePrint()
{
	struct Node* temp = head;
	if(temp == NULL)
	printf("The list is empty!\n");
	while(temp->next != NULL)
	{
		temp =  temp->next;
	}
	printf("Reverse: ");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
void main()
{
	int ch,i,j;
	head = NULL;
	for(;;)
	{
	printf("Enter\n1.Insert\n2.Print\n3.Reverse Print\n4.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		{
			printf("Enter the element to be inserted : ");
			scanf("%d",&i);
			InsertAtHead(i);
			Print();
			ReversePrint();
			break;
		}
		case 2:
		{
			Print();
			break;
		}
		case 3:
		{
			ReversePrint();
			break;
		}
		case 4:
		{
			exit(0);
		}
		default:
		printf("Wrong choice entered!\n");
	}
	}
}
