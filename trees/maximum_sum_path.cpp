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
int maxpathsum_util(Node * root,int &res)
{
  if(root==NULL) return 0;
  if(root->left==NULL&&root->right==NULL) return root->val;

  int ls=maxpathsum_util(root->left,res);
  int rs=maxpathsum_util(root->right,res);

  if(root->left&&root->right)
  {
    res=max(res,ls+rs+root->val);
    return max(ls,rs)+root->val;
  }

  if(root->left==NULL)
    return rs+root->val;
  else
    return ls+root->val;
}

int maxPathSum(Node * root)
{
  if(root)
  {
    int res=INT_MIN;
    maxpathsum_util(root,res);
    return res;
  }
  else
    return 0;
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
  cout<<maxPathSum(root)<<endl;
}
