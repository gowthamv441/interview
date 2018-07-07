#include <iostream>
using namespace std;

typedef struct node
{
  int val;
  node* prev;
  node * next;
}Node;

Node * newnode(int v)
{
  Node * temp=new node();
  temp->val=v;
  temp->prev=NULL;
  temp->next=NULL;
  return temp;
}

Node * insert_at_end(Node * head,int v)
{
  if(head==NULL)
    return newnode(v);
  Node * temp=head;
  while(temp->next)
  {
    temp=temp->next;
  }
  Node * p=newnode(v);
  p->prev=temp;
  temp->next=p;
  return head;
}

Node * insert_at_front(Node * head,int v)
{
  if(head==NULL)
    return newnode(v);
  Node * temp=head;
  while(temp->prev)
  {
    temp=temp->prev;
  }
  Node * p=newnode(v);
  p->next=temp;
  temp->prev=p;
  return p;
}

Node * insert_at_pos(Node * head,int pos,int v)
{

  if(head==NULL)
  {
    if(pos==1)
      return newnode(v);
    else
    {
      cout<<"ERROR"<<endl;
      return NULL;
    }
  }
  int count=1;
  Node * temp=head;
  while(count<pos)
  {
    if(temp)
    {
      temp=temp->next;
    }
    else
    {
      cout<<"Index Error"<<endl;
      return head;
    }
    count++;
  }
  Node *c=newnode(v);
  Node *n=temp->next;
  Node *p=temp;
  c->next=n;
  p->next=c;
  n->prev=c;
  c->prev=p;
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

int main()
{
  Node * head=NULL;

  // insert at the end
  head=insert_at_end(head,1);
  head=insert_at_end(head,2);
  head=insert_at_end(head,3);
  head=insert_at_end(head,4);
  head=insert_at_end(head,5);

  print(head);

  // insert at the front
  head=NULL;
  head=insert_at_front(head,1);
  head=insert_at_front(head,2);
  head=insert_at_front(head,3);
  head=insert_at_front(head,4);
  head=insert_at_front(head,5);

  print(head);

  head=NULL;

  // insert at the end
  head=insert_at_end(head,1);
  head=insert_at_end(head,2);
  head=insert_at_end(head,3);
  head=insert_at_end(head,4);
  head=insert_at_end(head,5);

  print(head);

  // insert at the pos with hardcoded position

  int pos = 3; // 1 based indexing
  head=insert_at_pos(head,pos,6);
  print(head);
}
