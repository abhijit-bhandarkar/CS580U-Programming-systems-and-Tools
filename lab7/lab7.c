#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

//To create a node
struct node *createNode(struct data value1)
	{
	struct node *node1 = (struct node*) malloc(sizeof(struct node));
	node1->value = value1;
	node1->left = NULL;
	node1->right = NULL;
	node1->parent = NULL;
	return node1;
	}

//To create a Tree
struct tree *createTree()
	{
	struct tree *tree_root = (struct tree*) malloc(sizeof(struct tree));
	tree_root->root = NULL;
	return tree_root;
	}	

//Helper Function to insert a node
void insertNode(struct node *node, struct data data1)
{
	struct node *node1 = createNode(data1);

	if((data1.info) == (node->value.info))
	printf("\nNode with the value %d already present.\nCannot insert duplicate values.\n",data1.info);

	if((data1.info) < (node->value.info))
		{
		if(node->left == NULL)
		{
			node1->parent = node;
			printf("\n%d is parent of %d\n", node1->parent->value.info, node1->value.info);
			node->left = node1;
			printf("%d added to left of %d\n", node1->value.info, node->value.info);
		}
		else
			insertNode(node->left,data1);
		}

	if((data1.info) > node->value.info)
		{	
		if(node->right == NULL)
		{
			node1->parent = node;
			printf("\n%d is parent of %d\n", node1->parent->value.info, node1->value.info);
			node->right = node1;
			printf("%d added to right of %d\n", node1->value.info, node->value.info);
		}
		else
			insertNode(node->right,data1);
		}	

}


//Function to insert node
void insert(struct tree *bst, struct data data1)
{
	struct node *node1 = createNode(data1);

	if(bst->root == NULL)
	{
		bst->root = node1;
		printf("%d added to root node\n", node1->value.info);
	}
	else
	{
		insertNode(bst->root,data1);
	}

}

//Helper Function to search node
struct node *searchNode(struct node *node, struct data data1)
{
	struct node *temp;
	temp = node; 

	if(node == NULL)  
	{
		printf("\nNode %d not found\n",data1.info);
		return 0; 
	}		
	else
	{
		if(data1.info == (node->value.info))
		{
		printf("\nNode %d found\n",node->value.info);
		return node;
		}
	
		else if (data1.info < (node->value.info))
		return searchNode(node->left, data1);

		else if((data1.info) > (node->value.info))
		return searchNode(node->right, data1);
	}
    
}

//Function to search node in the tree
struct node *search (struct tree *bst, struct data data1)
{
	if(bst->root->value.info == data1.info)
	{
	 return bst->root;
	}
	
	else
	{
	return searchNode(bst,data1);
	}

}

void display(struct node *node)
{
	struct node *node1 = (struct node*) malloc(sizeof(struct node));
	node1 = node;
	if(node1 != NULL )	
  
	{	if(node1->parent != NULL )	
		printf("Parent of the node is :%d\n",node1->parent->value.info);
		else
		printf("This is the root node. No parent of this node\n");

		if (node1->left != NULL)
		printf("Left child of the node is :%d\n",node1->left->value.info);
		else
		printf("No Left child of this node\n");

		if (node1->right != NULL)
		printf("Right child of the node is %d\n",node1->right->value.info);
		else
		printf("No Right child of this node\n");
  	}
}

void main()
{
 int num, search_number;
 struct tree *new_tree = createTree();
 struct node *new_node;
 struct data data2;
 FILE *fp;

 fp = fopen("file.txt", "r");
 	while(fscanf(fp,"%d",&num) != EOF)
	{
	data2.info = num;
	insert(new_tree,data2);
	} 
	fclose(fp);


	do
	{
		printf("Enter the value to be searched in the tree\n");
		scanf("%d",&search_number);
		data2.info = search_number;
		display(search(new_tree,data2));
		printf("\n");
	}while(search_number != 0);

 free(new_tree->root);
 free(new_tree);
}
