#include <bits/stdc++.h>
using namespace std;
bool check_valid(string s,int i,int j)
{
  return (s[i]=='1'||s[i]=='2')&&(s[j]>='0'&&s[j]<='6');
}

int count_encoding(int index,string s,string ans)
{
  if(index>=s.length())
  {
    cout<<ans<<endl;
    return 1;
  }
  if(index+1<s.length())
  {
    if(check_valid(s,index,index+1))
      return count_encoding(index+2,s,(ans+s[index]+s[index+1]+" "))+count_encoding(index+1,s,(ans+s[index]+" "));
    else if(s[index]>='1'&&s[index]<='9')
      return count_encoding(index+1,s,(ans+s[index]+" "));
  }
  else
  {
    if(s[index]>='1'&&s[index]<='9')
      return count_encoding(index+1,s,(ans+s[index]+" "));
  }
  return 0;
}

main()
{
  string s;
  cin>>s;
  cout<<count_encoding(0,s,"")<<endl;
}
