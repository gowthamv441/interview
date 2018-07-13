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
Node * array_to_tree(Node * &root,vector<int> &arr,int l,int r)
{
  if(l>r)
    return NULL;
  int mid=l+(r-l)/2;
  root=newnode(arr[mid]);
  array_to_tree(root->left,arr,l,mid-1);
  array_to_tree(root->right,arr,mid+1,r);
  return root;
}
main()
{
  vector<int> arr={1,2,3,4,5};
  Node *new_root=new Node();
  array_to_tree(new_root,arr,0,4);
  print(new_root);
}
