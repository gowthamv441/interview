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
int diameter_util(Node * root,int &res)
{
  if(root==NULL)
    return 0;
  int ls=1+diameter_util(root->left,res);
  int rs=1+diameter_util(root->right,res);
  if(root)
  {
    res=max(res,(ls+rs)-1);
    return max(ls,rs);
  }
}
int diameter(Node * root)
{
    int res=0;
    diameter_util(root,res);
    return res;
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
  cout<<diameter(root)<<endl;
}
