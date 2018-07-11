#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
  int val;
  node * left;
  node * right;
}Node;
Node * newnode(int v)
{
  Node * temp=new Node();
  temp->val=v;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
void print(Node * root)
{
  if(root)
  {
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
  }
}
void convert(Node * root,Node **head)
{
  if(root==NULL)
    return ;
  /* static is important */
  static Node * prev=NULL;
  convert(root->left,head);
  if(prev==NULL)
    *head=root;
  else
  {
    root->left=prev;
    prev->right=root;
  }
  prev=root;
  convert(root->right,head);
}
void print_dll(Node * head)
{
  while(head)
  {
    cout<<head->val<<" ";
    head=head->right;
  }
}
main()
{
  Node * root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(3);
  root->left->left=newnode(4);
  root->left->right=newnode(5);
  root->right->left=newnode(6);
  root->right->right=newnode(7);
  print(root);
  cout<<endl;
  Node * head=NULL;
  convert(root,&head);
  print_dll(head);
}
