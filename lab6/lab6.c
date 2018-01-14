#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Myfile.h"

struct list *create_List()
{
 struct list *new_list;
 new_list = (struct list*) malloc(sizeof(struct list));
 new_list->first = 0;
 return new_list;
}

//To create node for singly linked list
struct node *create_Node(int num)
{
 struct node *new_node;
 new_node = (struct node*) malloc(sizeof(struct node));
 new_node->data = num;
 return new_node;
}

//To return the head node of the list
struct node *front(struct list *list)
{
 struct node *front_node = list->first;
 return front_node;
}

//To insert a node in the list
struct node *insert(struct list *list, int index, int num_data)
{	
   struct node * current, *prev;
   struct node * new_node = create_Node(num_data);
   if(list->first==0)
   {
	list->first=new_node;
	return new_node;
   }
   prev=list->first;
   current = list->first;
   int temp_index = 0;
	 
   while (current->next != 0 && temp_index < index)
   {
     prev=current;	
     current = current->next;
     temp_index = temp_index + 1;
   }

	 if(current->next == 0)
	{
		current->next=new_node;
		return new_node;
	}
	else
	{
		new_node->next=current;
		prev->next=new_node;
	}

return new_node;
}

//To print the singly linked list
void print_List(struct list *list_print)
{
  struct node * current = list_print->first;
  printf("-----------------------------------------------------\n");
  while (current != 0)
      {
         printf("Address of the node: %u \n", current);
         printf("Data in the node : %d \n", current->data);
         current = current->next;
      }
 
}

//To delete the node from the list
int delete(struct list *list, int index)
{
   struct node *current = front(list);		//Gets the first node
   struct node *prev;
   int data;
   int temp_index = 0;
  //If list is empty
    if(current == 0)
    {
	printf("Empty list");
	return 0;
    }		
    
    while( current != 0 && temp_index != index)
    {
       	prev = current;	
     	current = current->next;
	temp_index = temp_index + 1;	
    }
  //If head node is to be deleted
    if (index == 0)
    {
        data = list->first->data;
	list->first = list->first->next;
        return data;
    }

	prev->next = current->next;
	free(current);   
	return 0;
}

//To create node in doubly linked list
struct node_double *create_Node_double(int num)
{
	struct node_double *new_node_double = (struct node_double*) malloc(sizeof(struct node_double));
 	new_node_double->data = num;
 //	printf("Data in the node is %d\n",new_node_double->data);

	new_node_double->next = NULL;
 	new_node_double->prev = NULL;
 //	printf("Address of the node is %u\n",new_node_double);
 	return new_node_double;
}


//To insert node in the doubly linked list
struct node_double *insert_doubly(int num_data)
{	
   struct node_double * current_double = head_double;
   struct node_double * new_node_double = create_Node_double(num_data);
   if(head_double == 0)
   {
	{
	head_double = new_node_double;
	return new_node_double;
   	}

	head_double->prev = new_node_double;
	new_node_double->next = head_double;
	head_double = new_node_double;  
   }
   else
   {	
	while(current_double->next != NULL) 
	current_double = current_double->next; // Go To last Node
	current_double->next = new_node_double;
	new_node_double->prev = current_double;
   }
}

//To search values in the doubly linked list from head
void search_Forward()
{
 struct node_double *current_double = head_double;
 printf("Double Linked list in Forward way:\n");
	while(current_double != NULL) {
		printf("%d ",current_double->data);
		current_double = current_double->next;
	}
	printf("\n");
}

//To search values in the doubly linked list from back
void search_Backward() 
{
	struct node_double* current_double = head_double;
	if(current_double == NULL) return; // empty list, exit
	// Going to last Node
	while(current_double->next != NULL) {
		current_double = current_double->next;
	}
	// Traversing backward using prev pointer
	 printf("Double Linked list in Backword way:\n");
	while(current_double != NULL) {
		printf("%d ",current_double->data);
		current_double = current_double->prev;
	}
	printf("\n");
}

int search(int number)
{
 int count = 0; 
 struct node_double *current_double = head_double;
	while(current_double != NULL) 
	{
		if( number == current_double->data)
		{
		 printf("%d is found at index %d\n",number,count);
		 return 0;
		}		
 		else 
		{
		current_double = current_double->next;
		count++;	
		}
	}
	printf("%d is not found in the doubly linked list\n",number);

}

//To display stack elements
int display_stack(struct stack *s)
{
    int i;
    if (s->top == -1)
    {
        printf ("Stack is empty\n");
        return 0;
    }
    else
    {
        printf ("Elements of the stack : \n");
        for (i = s->top; i >= 0; i--)
        {
            printf ("%d\n", s->stack_size[i]);
        }
    }
    printf ("\n");
}

//To push elements into the stack
int push(struct stack *s, int value)
{
    if (s->top == (SIZE - 1))
    {
        printf ("Stack is Full\n");
        return 0;
    }
    else
    {
        s->top = s->top + 1;
        s->stack_size[s->top] = value;
    }
    return 0;
}

//To ppo element from the stack
int pop(struct stack *s)
{
    int num;
    if (s->top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s->top);
    }
    else
    {	
        num = s->stack_size[s->top];
        s->top = s->top - 1;
    }
    return(num);
}

//Initial values of front and rear node of queue
struct node *head_q = NULL;
struct node *tail_q = NULL;

// To Enqueue an integer
void enqueue(struct queue *q_name, int value)
{	
	struct node *temp_q = (struct node*) malloc(sizeof(struct node));

	temp_q->data = value; 
	temp_q->next = NULL;

	if(head_q == NULL && tail_q == NULL)
	{
		head_q = tail_q = temp_q;
		return;
	}
	tail_q->next = temp_q;
	tail_q = temp_q;
}

//To display queue
void print_q() 
{
	struct node* temp_q = head_q;
	while(temp_q != NULL) 
	{
		printf("%d ",temp_q->data);
		temp_q = temp_q->next;
	}
	printf("\n");
}

// To Dequeue an integer.
void dequeue(struct queue *q_name) 
{
	struct node* temp_q = head_q;
	if(head_q == NULL) 
	{
		printf("Queue is Empty\n");
		return;
	}
	if(head_q == tail_q) 
	{
		head_q = tail_q = NULL;
	}
	else 
	{
		head_q = head_q->next;
	}
	free(temp_q);
}


void main()
{

 printf("\n\n-----------PART 1 : Model Train --------------\n\n");
 struct train *head;		//struct too store the address of   first car
 head =(struct train*) malloc(sizeof(struct train));
 (head->first) = head;
 
 struct car *temp;
 struct car *next;
 int number_of_cars, i;

 printf("Enter the number of cars in the train\n");
 scanf("%d",&number_of_cars);

 if(number_of_cars != 0)
 {
 printf("Total number of cars in the train are : %d\n\n",number_of_cars);
 printf("The address of first car is : %u\n", head->first);
 }
 else
 printf("There are no cars in the train \n");

	i = 1;
	while(number_of_cars != 0)
	{
 	temp =(struct car*) malloc(sizeof(struct car));
 	next =(struct car*) malloc(sizeof(struct car));

 	next = temp;

 	printf("Enter the cargo weight of car %d\n", i); 
 	scanf("%d", &(next->cargo_weight));

 	printf("The cargo weight of car %d is : %d \n\n", i, next->cargo_weight);
 	free(temp);
 		if(number_of_cars != 1)
 		{
		temp =(struct car*) malloc(sizeof(struct car));
		next->Next = temp;
		printf("The Address of car %d is : %u\n", (i+1), next->Next);
 		}
 		else
		{
  		next->Next = 0;
 		printf("There are no more cars in the train\n\n");
		}
	number_of_cars--;
	i++;
    	}

time_t t;
srand((unsigned) time(&t));

printf("\n-----------PART 2 (A) : Singly Linked List --------------\n\n");

struct list *ONE = create_List(); //Creating a list

insert(ONE,0, rand()%50);
insert(ONE,1, rand()%50);
insert(ONE,2, rand()%50);
insert(ONE,3, rand()%50);
insert(ONE,4, rand()%50);
insert(ONE,5, rand()%50);
insert(ONE,6, rand()%50);
insert(ONE,7, rand()%50);
insert(ONE,8, rand()%50);
insert(ONE,9, rand()%50);

printf("Original List\n");
print_List(ONE);


printf("Enter the index to be deleted from Singly linked list\n");
int del_index;
scanf("%d",&del_index);
delete(ONE,del_index);
printf("\nList after deleting one element\n");
print_List(ONE);

printf("\n-----------PART 2 (B) : Doubly Linked List --------------\n\n");

insert_doubly(rand()%50);
insert_doubly(rand()%50);
insert_doubly(rand()%50);
insert_doubly(rand()%50);
insert_doubly(rand()%50);
insert_doubly(rand()%50);
insert_doubly(rand()%50);
insert_doubly(rand()%50);
insert_doubly(rand()%50);
insert_doubly(rand()%50);

search_Forward();
printf("\n");

search_Backward();
printf("\n");

int search_number;
printf("Enter the value to search in doubly linked list:\n");
scanf("%d",&search_number);
search(search_number);

printf("\n------------------- PART 3 (A) : STACK --------------------\n\n");

struct stack *s;
s = (struct stack*) malloc(sizeof(struct stack));
s->top = -1;

int element[5], e;
printf("Enter 5 values in the stack:\n\n");
	for(e = 0; e < 5; e++)
	{
	printf("Input %d :\t",e+1); 
	scanf("%d",&element[e]);	
	push(s,element[e]);
	}	
printf("\n");
//push(s,55);

display_stack(s);
pop(s);
printf ("Stack after pop operation:\n");
display_stack(s);

printf("\n------------------- PART 3 (B) : QUEUE --------------------\n\n");

struct queue *new_queue;
new_queue = (struct queue*)malloc(sizeof(struct queue));
new_queue->q_head = NULL;
new_queue->q_tail = NULL;

int q_element[5], q;
printf("Enter 5 values in the queqe:\n\n");
for(q = 0; q < 5; q++)
{
	printf("Input %d :\t",q+1); 
	scanf("%d",&q_element[q]);
	
	enqueue(new_queue,q_element[q]);
}

printf("\nQueue after enqueue operation\n");
print_q(); 

dequeue(new_queue); 
printf("\nQueue after dequeue operation\n");
print_q(); 

}


