#include <bits/stdc++.h>
using namespace std;
int find_index(string s)
{
  pair <int,int> arr[256];
  for(int i=0;i<s.length();i++)
  {
    arr[s[i]].first++;
    arr[s[i]].second=i;
  }
  int res=INT_MAX;
  for(int i=0;i<256;i++)
  {
      if(arr[i].first==1)
      {
        res=min(res,arr[i].second);
      }
  }
  return res;
}
main()
{
  string s;
  cin>>s;
  int index=find_index(s);
  if(index==INT_MAX)
    cout<<"-1"<<endl;
  else
    cout<<s[index]<<endl;
}
