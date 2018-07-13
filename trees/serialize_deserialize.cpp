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
void serialize(Node *root,vector<int> &A)
{
    if(root==NULL)
    {
        A.push_back(-1);
        return;
    }
    A.push_back(root->val);
    serialize(root->left,A);
    serialize(root->right,A);
}
void deserialize_util(Node* &root,vector<int> &A,int &index)
{
    if(A[index]==-1)
        return;
    root=newnode(A[index]);
    index+=1;
    deserialize_util(root->left,A,index);
    index+=1;
    deserialize_util(root->right,A,index);
}

Node * deSerialize(vector<int> &A)
{
   Node * root=new Node();
   int index=0;
   deserialize_util(root,A,index);
   return root;
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
  vector<int> A;
  serialize(root,A);
  Node * new_root=deSerialize(A);
  print(new_root);
  cout<<endl;

}
