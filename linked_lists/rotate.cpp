/*
Input:
1->2->3->4->5  3
Output:
4->5->1->2->3
 */
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

Node* rotate(Node* head,int k)
{
  Node * temp=head;
  while(k>1&&temp)
  {
    k--;
    temp=temp->next;
  }
  if(k==1&&temp)
  {
    Node * runner=temp->next;
    Node * start=temp->next;
    temp->next=NULL;
    while(runner->next)
      runner=runner->next;
    runner->next=head;
    head=start;
  }
  return head;
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
  head=rotate(head,6);
  print (head);
}
