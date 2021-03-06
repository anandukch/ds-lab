// binary tree using linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
};

void insertNode(int data, Node *node)
{
  char choice;
  node->data = data;
  printf("Does the node %d has left child : y/n : ", data);
  scanf("%s", &choice);
  if (choice == 'y')
  {
    printf("Enter the left child data: ");
    int leftChildData;
    scanf("%d", &leftChildData);
    node->left = createNode();
    insertNode(leftChildData, node->left);
  }
  printf("Does the node %d has right child  : y/n : ", data);
  scanf("%s", &choice);
  if (choice == 'y')
  {
    printf("Enter the right child data: ");
    int rightChildData;
    scanf("%d", &rightChildData);
    node->right = createNode();
    insertNode(rightChildData, node->right);
  }
}
void initializeInsertion(Node *root)
{

  int item;
  printf("Enter the root node data: ");
  scanf("%d", &item);
  insertNode(item, root);
};

void inorderTraversal(Node *node)
{
  if (node != NULL)
  {
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
  }
}

void postOrderTraversal(Node *node)
{
  if (node != NULL)
  {
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d ", node->data);
  }
}
void preOrderTraversal(Node *node)
{
  if (node != NULL)
  {
    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
  }
}

int main()
{
  Node *root = createNode();
  initializeInsertion(root);
  preOrderTraversal(root);
}