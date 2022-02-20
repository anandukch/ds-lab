// binary tree using linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// void initializeInsertion(Node*);
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
};

void insertNode(int data, Node *node)
{
  char choice;
  Node *newNode = createNode(data);
  node = newNode;
  printf("Does the node has left child: y/n : ");
  scanf("%s", &choice);
  if (choice == 'y')
  {
    printf("Enter the left child data: ");
    int leftChildData;
    scanf("%d", &leftChildData);
    return insertNode(leftChildData, node->left);
  }
  printf("Does the node has right child: y/n : ");
  scanf("%s", &choice);
  if (choice == 'y')
  {
    printf("Enter the right child data: ");
    int rightChildData;
    scanf("%d", &rightChildData);
    return insertNode(rightChildData, node->right);
  }
}
void initializeInsertion(Node *root)
{

  int item;
  printf("Enter the node data: ");
  scanf("%d", &item);
  insertNode(item, root);
};

void inorderTraversal(Node *node)
{
  if (node == NULL){
    return;
  }
  inorderTraversal(node->left);
  printf("%d ", node->data);
  inorderTraversal(node->right);
}

int main()
{
  Node *root = NULL;
  initializeInsertion(root);
  inorderTraversal(root);
}
