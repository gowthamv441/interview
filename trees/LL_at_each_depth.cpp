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
Node * insert(Node * root,int val)
{
  if(root==NULL)
    return newnode(val);
  Node * temp=root;
  while(temp->right)
    temp=temp->right;
  temp->right=newnode(val);
  return root;
}
void LL_at_each_depth(Node * root,vector<Node *> &linked_lists)
{
  if(root==NULL)
    return;
  queue<Node *> q1;
  queue<Node *> q2;
  q1.push(root);
  Node * head;
  while(!q1.empty()||!q2.empty())
  {
      head=NULL;
      while(!q1.empty())
      {
        Node * tmp=q1.front();
        q1.pop();
        head=insert(head,tmp->val);
        if(tmp->left)
          q2.push(tmp->left);
        if(tmp->right)
          q2.push(tmp->right);
      }
      if(head!=NULL)
        linked_lists.push_back(head);
      head=NULL;
      while(!q2.empty())
      {
        Node * tmp=q2.front();
        q2.pop();
        head=insert(head,tmp->val);
        if(tmp->left)
          q1.push(tmp->left);
        if(tmp->right)
          q1.push(tmp->right);
      }
      if(head!=NULL)
        linked_lists.push_back(head);
  }

}
void print_linked_list(Node * root)
{
  while(root)
  {
    cout<<root->val<<" ";
    root=root->right;
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
  vector<Node *> linked_lists;
  LL_at_each_depth(root,linked_lists);
  for(int i=0;i<linked_lists.size();i++)
  {
    print_linked_list(linked_lists[i]);
    cout<<endl;
  }
}
