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
void print_path(vector<int> a,int l)
{
  for(int i=l;i<a.size();i++)
    cout<<a[i]<<" ";
  cout<<endl;
}
void print_all_paths(Node * root,vector<int> a,int k)
{
  if(root)
  {
    a.push_back(root->val);
    print_all_paths(root->left,a,k);
    print_all_paths(root->right,a,k);
    int sum=0;
    for(int j=a.size()-1;j>=0;j--)
    {
      sum+=a[j];
      if(sum==k)
        print_path(a,j);
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
  vector<int> a;
  print_all_paths(root,a,4);
}
