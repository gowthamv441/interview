#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
  int val;
  node * left;
  node * right;
  node * nextright;
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
Node * getnextright(Node * p)
{
  if(p->nextright==NULL)
    return NULL;
  Node * temp=p->nextright;
  if(temp->left)
    return temp->left;
  else if(temp->right)
    return temp->right;
  else
    return getnextright(temp);
}
void connect(Node * p)
{
  if(!p)
    return ;
  p->nextright=NULL;
  while(p)
  {
    Node * q=p;
    while(q)
    {
      if(q->left)
      {
        if(q->right)
          q->left->nextright=q->right;
        else
          q->left->nextright=getnextright(q);
      }
      if(q->right)
        q->right->nextright=getnextright(q);
      q=q->nextright;
    }
    if(p->left)
      p=p->left;
    else if(p->right)
      p=p->right;
    else
      p=getnextright(p);
  }
}
void print_connections(Node * p)
{
  if(!p)
    return;
  cout<<p->val<<" ";
  while(p)
  {
    Node * q=p;
    while(q)
    {
      if(q->left)
        cout<<q->left->val<<" ";
      if(q->right)
        cout<<q->right->val<<" ";
      q=q->nextright;
    }
    if(p->left)
      p=p->left;
    else if(p->right)
      p=p->right;
    else
      p=p->nextright;
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
  connect(root);
  print_connections(root);
}
