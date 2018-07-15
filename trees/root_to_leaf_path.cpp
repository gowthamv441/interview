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
void print_vector(vector<int> arr)
{
  for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}
void print_path(Node * root,vector<int> arr)
{
  if(root)
  {
    arr.push_back(root->val);
    if(root->left==NULL&&root->right==NULL)
    {
      print_vector(arr);
      return;
    }
    else
    {
      print_path(root->left,arr);
      print_path(root->right,arr);
    }
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
  vector<int> arr;
  print_path(root,arr);
}
