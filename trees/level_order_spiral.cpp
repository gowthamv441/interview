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
void spiral_printing(Node * root)
{
  if(root)
  {
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
      while(!s1.empty())
      {
        Node * tmp=s1.top();
        s1.pop();
        cout<<tmp->val<<" ";
        if(tmp->right)
          s2.push(tmp->right);
        if(tmp->left)
          s2.push(tmp->left);
      }
      while(!s2.empty())
      {
        Node * tmp=s2.top();
        s2.pop();
        cout<<tmp->val<<" ";
        if(tmp->left)
          s1.push(tmp->left);
        if(tmp->right)
          s1.push(tmp->right);
      }
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
  spiral_printing(root);
}
