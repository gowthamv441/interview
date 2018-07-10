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
bool check_bst(Node * root,int min,int max)
{
  if(root==NULL)
    return true;

  if(root->val<min||root->val>max)
  {
    return false;
  }
  return check_bst(root->left,min,root->val)&&check_bst(root->right,root->val,max);
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

  Node * bst_root=newnode(4);
  bst_root->left=newnode(2);
  bst_root->right=newnode(6);
  bst_root->left->left=newnode(1);
  bst_root->left->right=newnode(3);
  bst_root->right->left=newnode(5);
  bst_root->right->right=newnode(7);
  print(bst_root);
  cout<<endl;

  if(check_bst(root,INT_MIN,INT_MAX))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

  if(check_bst(bst_root,INT_MIN,INT_MAX))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
