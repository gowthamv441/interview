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
int check_balanced(Node * root,bool &flag)
{
  if(root==NULL)
    return 0;
  int ls=check_balanced(root->left,flag);
  int rs=check_balanced(root->right,flag);
  if(abs(ls-rs)>1)
    flag=false;
  return max(ls,rs)+1;
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
  bool flag=true;
  check_balanced(root,flag);
  if(flag)
    cout<<"yes"<<endl;
  else
    cout<<"No"<<endl;
}
