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

Node * lca(Node * root,int n1,int n2,bool &v1,bool &v2)
{
  if(root==NULL)
    return NULL;
  if(root->val==n1)
  {
    v1=true;
    return root;
  }
  if(root->val==n2)
  {
    v2=true;
    return root;
  }
  Node * left_lca=lca(root->left,n1,n2,v1,v2);
  Node * right_lca=lca(root->right,n1,n2,v1,v2);
  if(left_lca&&right_lca)
    return root;
  return (left_lca==NULL)?right_lca:left_lca;
}

bool find_key(Node * root,int val)
{
  if(root==NULL)
    return false;
  return root->val==val||find_key(root->left,val)||find_key(root->right,val);
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
  bool v1=false,v2=false;
  int n1=5,n2=7;
  Node * ans=lca(root,n1,n2,v1,v2);
  if((v1&&v2)||(find_key(root,n1)&&v2)||(v1&&find_key(root,n2)))
  {
    cout<<ans->val<<endl;
  }
  else
    cout<<"-1"<<endl;
}
