#include <iostream>
using namespace std;

typedef struct node
{
  int val;
  node * next;
}Node;

Node * newnode(int v)
{
  Node * temp=new Node();
  temp->val=v;
  temp->next=NULL;
  return temp;
}

Node * insert(Node * head,int v)
{
  if(head==NULL)
    return newnode(v);
  Node * t=head;
  while(t->next)
    t=t->next;
  t->next=newnode(v);
  return head;
}

void print(Node * head)
{
  while(head)
  {
    cout<<head->val<<" ";
    head=head->next;
  }
}
int length(Node * head)
{
  int len=0;
  while(head)
  {
    len++;
    head=head->next;
  }
  return len;
}
void modify(Node * head,int m,int n)
{
  Node * curr=head;
  while(curr)
  {
    for(int count=1;count<m&&curr;count++)
    {
      curr=curr->next;
    }
    if(curr==NULL)
      return;
    Node * t=curr->next;
    for(int count=1;count<=n&&t;count++)
    {
      Node * temp=t;
      t=t->next;
      free(temp);
    }
    curr->next=t;
    curr=t;
  }
}
main()
{
  Node * head=NULL;
  head=insert(head,1);
  head=insert(head,2);
  head=insert(head,3);
  head=insert(head,4);
  head=insert(head,5);
  print (head);
  cout<<endl;
  int m=1,n=1;
  modify(head,m,n);
  print(head);
}
