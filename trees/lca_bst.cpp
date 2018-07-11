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
bool find_node(Node * root,int n)
{
  if(root)
  {
    if(root->val==n)
      return true;
    return find_node(root->left,n)||find_node(root->right,n);
  }
  return false;
}
Node * find_lca(Node * root,int n1,int n2)
{
  if(root==NULL)
    return NULL;
  if(n1<root->val&&n2<root->val)
    return find_lca(root->left,n1,n2);
  else if(n1>root->val&&n2>root->val)
    return find_lca(root->right,n1,n2);
  return root;
}
main()
{
  Node * root=newnode(4);
  root->left=newnode(2);
  root->right=newnode(6);
  root->left->left=newnode(1);
  root->left->right=newnode(3);
  root->right->left=newnode(5);
  root->right->right=newnode(7);
  print(root);
  cout<<endl;
  int n1,n2;
  cin>>n1>>n2;
  if(find_node(root,n1)&&find_node(root,n2))
  {
    Node * lca=find_lca(root,n1,n2);
    cout<<lca->val<<endl;
  }
  else
    cout<<"-1"<<endl;
}
