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
Node * reverse_by_group(Node * head,int k)
{
  Node * curr=head;
  Node * prev=NULL;
  Node * next=NULL;
  int count=0;
  while (count<k) {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    count++;
  }
  if(next)
    head->next=reverse_by_group(next,k);
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
  head=insert(head,6);
  print (head);
  head=reverse_by_group(head,3);
  print(head);
}
