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
  cout<<endl;
}

Node * reverse(Node * head)
{
  Node * prev=NULL;
  Node * curr=head;
  Node * next=NULL;
  while(curr)
  {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  return prev;
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
  head=reverse(head);
  print(head);
}
