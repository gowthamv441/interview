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
bool check_mirror(Node * ptr1,Node * ptr2)
{
  if(ptr1==NULL&&ptr2==NULL)
    return true;
  if(ptr1&&ptr2)
  {
    return ptr1->val==ptr2->val&&check_mirror(ptr1->left,ptr2->right)&&check_mirror(ptr1->right,ptr2->left);
  }
  return false;
}
main()
{
  Node * root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(2);
  root->left->left=newnode(4);
  root->left->right=newnode(5);
  root->right->left=newnode(5);
  root->right->right=newnode(4);
  print(root);
  cout<<endl;
  if(check_mirror(root,root))
    cout<<"yes"<<endl;
  else
    cout<<"no"<<endl;
}
