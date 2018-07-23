#include <bits/stdc++.h>
using namespace std;

int count_encoding(string s)
{
  if(s[0]=='0')
    return 0;
  int count[s.length()+1];
  count[0]=1;
  count[1]=1;
  for(int i=2;i<=s.length();i++)
  {
    count[i]=0;
    if(s[i-1]>'0')
      count[i]=count[i-1];
    if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') )
      count[i]+=count[i-2];
  }
  return count[s.length()];
}
main()
{
  string s;
  cin>>s;
  cout<<count_encoding(s)<<endl;
}
