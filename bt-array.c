#include <stdio.h>
#define SIZE 50

void buildTree(char *tree, char data, int index)
{
  if (index == -1)
  {
    return;
  }
  tree[index] = data;
  char choice;
  printf("Does the node has left child: y/n : ");
  scanf("%s", &choice);
  if (choice == 'y')
  {
    printf("Enter the left child data: ");
    char leftChildData;
    scanf("%c", &leftChildData);
    buildTree(tree, leftChildData, 2 * index + 1);
  }
  else
    buildTree(tree, 0, -1);
  printf("Does the node has right child: y/n : ");
  scanf("%s", &choice);
  if (choice == 'y')
  {
    printf("Enter the right child data: ");
    char rightChildData;
    scanf("%c", &rightChildData);
    buildTree(tree, rightChildData, 2 * index + 2);
  }
  else
    buildTree(tree, 0, -1);
}
void inorder(char *tree, int index)
{

  if (tree[index] == '\0')
  {
    return;
  }
  inorder(tree, 2 * index + 1);
  printf("%c", tree[index]);
  inorder(tree, 2 * index + 2);
}
int main()
{
  char btree[SIZE];
  printf("Enter the root data: ");
  char rootData;
  scanf("%c", &rootData);
  btree[0] = rootData;
  buildTree(btree, rootData, 0);
  printf("%c", btree[10]);
  // inorder(btree, 0);
}