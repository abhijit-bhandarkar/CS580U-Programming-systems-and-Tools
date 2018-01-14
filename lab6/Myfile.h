
struct list *create_List();
struct node *create_Node(int num);
struct node *front(struct list *list);
struct node *insert(struct list *list, int index, int num_data);
void print_List(struct list *list_print);
int delete(struct list *list, int index);
struct node_double *create_Node_double(int num);
struct node_double *insert_doubly(int num_data);
void search_Forward();
void search_Backward(); 
int search(int number);
void print_q(); 


#define SIZE 5

//structure for car
struct car
{
 int cargo_weight;
 struct car *Next;  	   
};

//structure for train
struct train
{
 struct car *first;  
};


//node structure singly linked list
struct node
{
 int data;
 struct node *next;
};

//list structure for singly linked list
struct list
{
 struct node *first;
};

//node structure for doubly linked list
struct node_double
{
 int data;
 struct node_double *next;
 struct node_double *prev;
};

struct node_double *head = NULL;
struct node_double *head_double = NULL;
struct node_double *last = NULL;

//For stack
struct stack
{
    int stack_size[SIZE];
    int top;
};

//For queue
struct queue
{
	struct queue *q_head;
	struct queue *q_tail;
	int info;
};

