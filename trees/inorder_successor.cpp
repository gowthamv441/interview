#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
  int val;
  node * left;
  node * right;
  node * parent;
}Node;
Node * newnode(int v)
{
  Node * temp=new Node();
  temp->val=v;
  temp->left=NULL;
  temp->right=NULL;
  temp->parent=NULL;
  return temp;
}
Node * insert(Node * root,int v)
{
  if(root==NULL)
    return newnode(v);
  else
  {
    Node * temp;
    if(root->val>v)
    {
      temp=insert(root->left,v);
      root->left=temp;
      temp->parent=root;
    }
    else
    {
      temp=insert(root->right,v);
      root->right=temp;
      temp->parent=root;
    }
  }
  return root;
}
void print(Node * root)
{
  if(root)
  {
    print(root->left);
    cout<<root->val<<" ";
    print(root->right);
  }
}
Node * find_min(Node * root)
{
  while(root->left)
    root=root->left;
  return root;
}
/*
Algorithm:
  return right child if the node has right child;
  else
    iterate through parent until the curr node become left child to ancestor.
*/
Node * inorder_successor(Node * root)
{
  if(root==NULL)
    return NULL;
  if(root->right)
  {
    Node * ans=find_min(root->right);
    return ans;
  }
  Node * p=root->parent;
  while(p!=NULL)
  {
    if(p->left==root)
      return p;
    root=p;
    p=p->parent;
  }
  return NULL;
}

/*
Another Method without using parent pointer
*/
Node * inorder_succ_no_parent(Node * root,Node * temp)
{
  if(root==NULL)
    return NULL;
  if(temp->right)
    return find_min(temp->right);
  Node * succ=NULL;
  while(root)
  {
    if(temp->val<root->val)
    {
        succ=root;
        root=root->left;
    }
    else if(temp->val>root->val)
    {
      root=root->right;
    }
    else
      break;
  }
  return succ;
}
main()
{
  Node * root=NULL;
  root=insert(root,4);
  root=insert(root,2);
  root=insert(root,6);
  root=insert(root,1);
  root=insert(root,3);
  root=insert(root,5);
  root=insert(root,7);
  print(root);
  Node * temp=root->left->right;
  cout<<endl;
  Node *ans=inorder_successor(temp);
  if(ans!=NULL)
    cout<<ans->val<<endl;
  else
    cout<<-1<<endl;

  ans=inorder_succ_no_parent(root,temp);
  if(ans!=NULL)
    cout<<ans->val<<endl;
  else
    cout<<-1<<endl;
}
