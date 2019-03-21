#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
	int height;
};

struct node *root=NULL;

struct node *newnode(int key)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->left=ptr->right=NULL;
	ptr->data=key;
	ptr->height=0;
	return ptr;
}

struct node *insert(struct node *ptr,int key)
{
	if(ptr==NULL)
	{
		ptr=newnode(key);
		if(root==NULL)
			root=ptr;
		return ptr;
	}
	if(ptr->data>=key)
		ptr->left=insert(ptr->left,key);
	else 
		ptr->right=insert(ptr->right,key);
	int hl=-1,hr=-1;
		if(ptr->left) hl=ptr->left->height;
		if(ptr->right) hr=ptr->right->height;
	ptr->height=max(hl,hr)+1;	
	return ptr;
}

int Findmin(struct node* ptr)
{
	while(ptr->left!=NULL)
		ptr=ptr->left;
	return ptr->data;
}

struct node *delete(struct node *ptr,int key)
{
	if(ptr==NULL)
		return ptr;
	if(ptr->data>key)
		ptr->left=delete(ptr->left,key);
	else if(ptr->data<key)
		ptr->right=delete(ptr->right,key);
	else
	{
		if(ptr->left==NULL)
			ptr=ptr->right;
		else if(ptr->right==NULL)
			ptr=ptr->left;
		else
		{
			ptr->data=Findmin(ptr->right);
			ptr->right=delete(ptr->right,ptr->data);
		}
	}
	return ptr;
}

void display(struct node *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d ",ptr->data);
	display(ptr->left);
	display(ptr->right);
	return;
}

int search(struct node *ptr,int key)
{
	if(ptr==NULL)
		return 0;
	if(ptr->data>key)
		search(ptr->left,key);
	else if(ptr->data<key)
		search(ptr->right,key);
	else
		return 1;
}	

int main()
{
	int i,n;
	printf("Enter 1)Insert 2)Delete 3)Display preorder 4)Search 5)Exit\n");
	scanf("%d",&n);
	while(n!=5)
	{
		if(n==1)
		{
			scanf("%d",&i);
			insert(root,i);
		}
		else if(n==2)
		{
			scanf("%d",&i);
			delete(root,i);
		}
		else if(n==3) display(root),printf("\n");
		else 
		{
			scanf("%d",&i);
			if(search(root,i))
				printf("Element is present\n");
			else 
				printf("Element is absent\n");
		}
	printf("Enter 1)Insert 2)Delete 3)Display preorder 4)Search 5)Exit\n");
	scanf("%d",&n);	
	}
return 0;
}