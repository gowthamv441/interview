#include <bits/stdc++.h>
using namespace std;
main()
{
  string s="I love code";
  string str="";
  map< int,vector<string> > mp;
  for(int i=0;i<=s.length();i++)
  {
    if(s[i]==' ' || s[i]=='\0')
    {
      if(mp.find(str.length())==mp.end())
      {
        vector<string> a;
        a.push_back(str);
        mp.insert(make_pair(str.length(),a));
        a.pop_back();
      }
      else
      {
        mp[str.length()].push_back(str);
      }
      str="";
    }
    else
      str+=s[i];
  }
  map< int,vector<string> > :: iterator it;
  for(it=mp.begin();it!=mp.end();it++)
  {
    cout<<it->first<<endl;
    vector<string> a=it->second;
    for(int i=0;i<a.size();i++)
      cout<<a[i]<<" ";
    cout<<endl;
  }
}
