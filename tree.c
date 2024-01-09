#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
	struct node *left,*right; 
}NODE;
 NODE  *create(NODE  *root)
{
	int i,n;
	NODE *temp,*newnode, *parent;
	printf("enter limit:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(NODE *)malloc(sizeof(NODE));
		printf("enter value:");
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
			continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;
			if(newnode->data<temp->data)
		          temp=temp->left;
		    else
		          temp=temp->right;
		}
		 if(newnode->data<parent->data)
		     parent->left=newnode;
		 else
		    parent->right=newnode;
		 }
	return root;
}
void inorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->data);
		inorder(temp->right);
	}
}
void preorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
	   printf("%d\t",temp->data);
	   preorder(temp->left);
	   preorder(temp->right);
	}
}
void postorder(NODE *root)
{
	NODE *temp=root;
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->data);
	   	
	}
}
int main()
{
   NODE *root=NULL;
     root=create(root);
    printf("\nInorder Display:");
      inorder(root);
    printf("\nPreoder Display:");
      preorder(root);
    printf("\nPostorder Display:");
      postorder(root);
}
