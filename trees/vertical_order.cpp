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
void vertical_order(Node * root,map< int,vector<int> > &mp,int hd)
{
  if(root)
  {
    mp[hd].push_back(root->val);
    vertical_order(root->left,mp,hd-1);
    vertical_order(root->right,mp,hd+1);
  }
}
void print_vertically(map< int,vector<int> > mp)
{
  map< int,vector<int> > :: iterator  it;
  for(it=mp.begin();it!=mp.end();it++)
  {
    for(int i=0;i<(it->second).size();i++)
    {
      cout<<it->second[i]<<" ";
    }
    cout<<endl;
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
  map<int,vector<int>> mp;
  vertical_order(root,mp,0);
  print_vertically(mp);
}
