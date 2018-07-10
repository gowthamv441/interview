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
void left_view(Node * root,int level,int &maxlevel)
{
  if(root)
  {
    if(maxlevel<level)
    {
      cout<<root->val<<" ";
      maxlevel=level;
    }
    left_view(root->left,level+1,maxlevel);
    left_view(root->right,level+1,maxlevel);
  }
}
void right_view(Node * root,int level,int &maxlevel)
{
  if(root)
  {
    if(maxlevel<level)
    {
      cout<<root->val<<" ";
      maxlevel=level;
    }
    right_view(root->right,level+1,maxlevel);
    right_view(root->left,level+1,maxlevel);
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
  int maxlevel=-1;
  left_view(root,0,maxlevel);
  cout<<endl;
  maxlevel=-1;
  right_view(root,0,maxlevel);
  cout<<endl;
}
