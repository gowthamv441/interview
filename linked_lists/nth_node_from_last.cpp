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
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node * ptr1=head;
       Node * ptr2=head;
       for(int count=0;count<n;count++)
       {
           if(ptr1==NULL)
            return -1;
           ptr1=ptr1->next;
       }
       while(ptr1)
       {
           ptr1=ptr1->next;
           ptr2=ptr2->next;
       }
       return ptr2->val;
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
  cout<<getNthFromLast(head,2)<<endl;
}
