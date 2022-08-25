#include <stdio.h>
#include <stdlib.h>
// Salve rapaziada !!!
struct tnode {
  int v;
  struct tnode *left, *right;
};
typedef struct tnode node;

node *getNode(int val) {
  node *n = (node *)malloc(sizeof(node));
  n->v = val;
  n->left = NULL;
  n->right = NULL;
  return n;
}

node *insertNode(node *root, node *new) {
  if (root == NULL)
    return new;
  if (new->v <= root->v)
    root->left = insertNode(root->left, new);
  else
    root->right = insertNode(root->right, new);
  return root;
}

node *searchNode(node *r, int key) 
{
   if (r==NULL || r->v==key) return r; 
   if (key<=r->v) return searchNode(r->left,key);
   else           return searchNode(r->right,key); 
}

void preOrder(node *r){
  if (r==NULL) return;
  printf("%d\n",r->v);
  preOrder(r->left);
  preOrder(r->right);
}

void inOrder(node *r){
  if (r==NULL) return;
  inOrder(r->left);
  printf("%d\n",r->v);
  inOrder(r->right);
}
int main(void) {
  node *r = NULL, *n;
  r = insertNode(r, getNode(100));
  r = insertNode(r, getNode(80));
  r = insertNode(r, getNode(120));
  r = insertNode(r, getNode(70));
  r = insertNode(r, getNode(110));
  //printf("%d\n", r->v);
  //printf("%d\n", r->left->v);
  //printf("%d\n", r->right->v);
  //n=searchNode(r, 70);
  // printf("%d\n", searchNode(r, 70)->v)
  //if (n) printf("%d\n", n->v);
  //else   printf("%d not found\n",70);
  preOrder(r);
  printf("=================\n");
  inOrder(r);
  return 0;
}