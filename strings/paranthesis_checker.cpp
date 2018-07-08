#include <bits/stdc++.h>
using namespace std;
bool check(string str)
{
  stack<char> s;
  for(int i=0;i<str.length();i++)
  {
    if(str[i]=='['||str[i]=='{'||str[i]=='(')
    {
      s.push(str[i]);
      continue;
    }
    if(!s.empty())
    {
      if(str[i]==']')
      {
          char tmp=s.top();
          if(tmp=='[')
            s.pop();
          else
            return false;
      }
      else if(str[i]=='}')
      {
          char tmp=s.top();
          if(tmp=='{')
            s.pop();
          else
            return false;
      }
      else if(str[i]==')')
      {
          char tmp=s.top();
          if(tmp=='(')
            s.pop();
          else
            return false;
      }
    }
    else
      return false;
  }
  if(s.empty())
    return true;
  return false;
}
main()
{
  int test_case;
  cin>>test_case;
  for(int t=1;t<=test_case;t++)
  {
    string s;
    cin>>s;
    if(check(s))
      cout<<"balanced"<<endl;
    else
      cout<<"not balanced"<<endl;
  }
}
