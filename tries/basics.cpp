#include <iostream>
using namespace std;

typedef struct node
{
  node * letter[26];
  bool end;
}Node;

Node * getnode()
{
  Node * temp=new Node();
  for(int i=0;i<26;i++)
  {
    temp->letter[i]=NULL;
  }
  temp->end=false;
  return temp;
}

Node * insert(Node * root,string s)
{
  Node * temp=root;
  for(int i=0;i<s.length();i++)
  {
    int index=s[i]-'a';
    if(temp->letter[index]==NULL)
        temp->letter[index]=getnode();
    temp=temp->letter[index];
  }
  temp->end=true;
  return root;
}

bool search(Node * root,string s)
{
  Node * temp=root;
  for(int i=0;i<s.length();i++)
  {
    int index=s[i]-'a';
    if(temp->letter[index]==NULL)
      return false;
    temp=temp->letter[index];
  }

  return (temp&&temp->end);
}

int main()
{
  Node * root=getnode();

  root=insert(root,"hellohai");
  root=insert(root,"helloboys");

  if(search(root,"hello"))
    cout<<"yes"<<endl;
  else
    cout<<"no"<<endl;

}
