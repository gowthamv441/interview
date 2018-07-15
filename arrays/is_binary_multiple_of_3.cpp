#include <bits/stdc++.h>
using namespace std;
bool is_multiple(string s)
{
  int stage=0;
  for(int i=0;i<s.length();i++)
  {
    int digit=s[i];
    switch (stage) {
      case 0: if(digit=='1')
                stage=1;
              break;
      case 1: if(digit=='0')
                stage=2;
              else if(digit=='1')
                stage=0;
              break;
      case 2: if(digit=='0')
                stage=1;
              break;
    }
  }
  if(stage==0)
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
    cout<<is_multiple(s)<<endl;
  }
}
