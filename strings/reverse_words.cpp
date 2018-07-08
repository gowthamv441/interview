#include <bits/stdc++.h>
using namespace std;
string reverse(string str)
{

  string tmp="";
  stack<string> s;
  for(int i=0;i<str.length();i++)
  {
    if(str[i]!='.')
    {
        tmp=tmp+str[i];
    }
    else
    {
        if(tmp!="")
          s.push(tmp);
        tmp="";
    }
  }
  if(tmp!="")
    s.push(tmp);
  str="";
  while(!s.empty())
  {
      str=str+s.top()+".";
      s.pop();
  }
  str[str.length()-1]='\0';
  return str;
}

main()
{
  int test_case;
  cin>>test_case;
  for(int t=1;t<=test_case;t++)
  {
    string str;
    cin>>str;
    str=reverse(str);
    cout<<str<<endl;
  }
}
