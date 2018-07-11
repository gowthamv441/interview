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

void print_bottom_view(Node * root,map<int,int> &mp,int hd)
{
    if(root)
    {
        mp[hd]=root->val;
        print_bottom_view(root->left,mp,hd-1);
        print_bottom_view(root->right,mp,hd+1);
    }
}
void bottomView(Node *root)
{
   map<int,int> mp;
   print_bottom_view(root,mp,0);
   map<int,int> :: iterator it;
   for(it=mp.begin();it!=mp.end();it++)
   {
       cout<<it->second<<" ";
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
  bottomView(root);
}
