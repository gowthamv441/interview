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
bool has_path_sum(Node * root,int sum)
{
  if(root==NULL)
    return sum==0;
  else
  {
    bool ans=0;
    int subsum=sum-(root->val);
    if(subsum==0&&root->left==NULL&&root->right==NULL)
      return 1;
    if(root->left)
      ans=ans||has_path_sum(root->left,subsum);
    if(root->right)
      ans=ans||has_path_sum(root->right,subsum);
    return ans;
  }

}
main()
{
  Node * root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(3);
/*  root->left->left=newnode(4);
  root->left->right=newnode(5);
  root->right->left=newnode(6);
  root->right->right=newnode(7);
  print(root);
  cout<<endl;*/
  if(has_path_sum(root,3))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
