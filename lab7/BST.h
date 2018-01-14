
//Data structure
struct data 
{
 int info;
};

// Node structure
struct node
{
 struct node *left;
 struct node *right;
 struct node *parent;
 struct data value;
};

// Tree structure
struct tree
{
 struct node *root;
};

struct node *createNode(struct data value1);

struct tree *createTree();

void insertNode(struct node *node, struct data data1);

void insert(struct tree *bst, struct data data1);

struct node *searchNode(struct node *node, struct data data1);

struct node *search (struct tree *bst, struct data data1);

void display(struct node *node);


