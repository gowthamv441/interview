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
void delete_greater_nodes(Node* &head,int x)
{
  Node * temp=head;
  while(temp&&temp->val>x)
  {
    head=temp->next;
    free(temp);
    temp=head;
  }
  Node * prev=NULL;
  while(temp)
  {
    while(temp->val<=x&&temp)
    {
      prev=temp;
      temp=temp->next;
    }
    if(temp==NULL)
      return;
    Node * t=temp->next;
    free(temp);
    prev->next=t;
    temp=t;
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
  int x;
  cin>>x;
  delete_greater_nodes(head,x);
  print(head);
}
