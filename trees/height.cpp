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
void height(Node * root,int curr_height,int &max_height)
{
  if(root)
  {
    if(max_height<curr_height)
      max_height=curr_height;
    height(root->left,curr_height+1,max_height);
    height(root->right,curr_height+1,max_height);
  }
}
int new_height(Node * root)
{
  if(root==NULL)
    return 0;
  int l=1+new_height(root->left);
  int r=1+new_height(root->right);
  return max(l,r);
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
  int max_height=1;
  height(root,1,max_height);
  cout<<max_height<<endl;
  /* another method*/
  cout<<new_height(root)<<endl;
}
