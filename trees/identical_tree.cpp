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
bool identical(Node * root1,Node * root2)
{
  if(root1==NULL&&root2==NULL)
    return true;
  if(root1&&root2)
  {
      return root1->val==root2->val&&identical(root1->left,root2->left)&&identical(root1->right,root2->right);
  }
  return false;
}
main()
{
  Node * root1=newnode(1);
  root1->left=newnode(2);
  root1->right=newnode(3);
  root1->left->left=newnode(4);
  root1->left->right=newnode(5);
  root1->right->left=newnode(6);
  root1->right->right=newnode(7);
  print(root1);
  cout<<endl;

  Node * root2=newnode(1);
  root2->left=newnode(2);
  root2->right=newnode(3);
  root2->left->left=newnode(4);
  root2->left->right=newnode(5);
  root2->right->left=newnode(6);
  //root2->right->right=newnode(7);
  print(root2);
  cout<<endl;

  if(identical(root1,root2))
    cout<<"yes"<<endl;
  else
    cout<<"no"<<endl;
}
