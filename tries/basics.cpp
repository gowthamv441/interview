#include <bits/stdc++.h>
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

Node * delete_word(Node * root,string str)
{
  stack< pair<Node *,int> > s;
  Node * temp=root;
  int last;
  for(int i=0;i<str.length();i++)
  {
    int index=str[i]-'a';
    last=index;
    if(temp->letter[index])
    {
      s.push(make_pair(temp,index));
    }
    else
    {
      cout<<"No such Word exist"<<endl;
      return root;
    }
    temp=temp->letter[index];
  }
  cout<<temp->end<<" "<<char(last-'a')<<endl;
  if(temp&&temp->end)
  {
    while(!s.empty())
    {
      pair <Node *,int> pi=s.top();
      s.pop();
      Node * tmp=pi.first;
      int index=pi.second;
      Node * child=tmp->letter[index];
      bool flag=0;
      for(int i=0;i<26;i++)
      {
        if(child->letter[i]!=NULL)
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
      {
        tmp->letter[index]=NULL;
        tmp->end=false;
      }
      else
      {
      //  if(tmp->end==true)
      //  {
          cout<<tmp->end<<" "<<char(index+'a')<<endl;
          tmp->end=false;
      //  }
      }
    }
  }
  return root;
}


int main()
{
  Node * root=getnode();

  root=insert(root,"hello");
  root=insert(root,"hellohai");
  root=insert(root,"helloboys");

  if(search(root,"hello"))
    cout<<"yes"<<endl;
  else
    cout<<"no"<<endl;

  root=delete_word(root,"hello");

  if(search(root,"hello"))
    cout<<"yes"<<endl;
  else
    cout<<"no"<<endl;
}
