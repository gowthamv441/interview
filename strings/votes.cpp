/*
https://www.geeksforgeeks.org/find-winner-election-votes-represented-candidate-names/
*/
#include <bits/stdc++.h>
using namespace std;
bool mycmp(pair<string,int> a,pair<string,int> b)
{
  return a.second>b.second;
}
main()
{
  int n;
  cin>>n;
  vector<string> votes(n);
  map<string,int> mp;
  for(int i=0;i<n;i++)
  {
    cin>>votes[i];
    if(mp.find(votes[i])==mp.end())
      mp.insert(make_pair(votes[i],1));
    else
      mp[votes[i]]++;
  }
  vector< pair<string,int> > v;
  map<string,int> :: iterator it;
  for(it=mp.begin();it!=mp.end();it++)
  {
    v.push_back(make_pair(it->first,it->second));
  }
  sort(v.begin(),v.end(),mycmp);
  cout<<"Each Person's Vote Count "<<endl;
  for(int i=0;i<v.size();i++)
  {
    cout<<"\t"<<v[i].first<<"\t"<<v[i].second<<endl;
  }
  cout<<"The winner is "<<v[0].first<<" with votes of "<<v[0].second<<endl;
}
/*
IP:
13
john
johnny
jackie
johnny
john
jackie
jamie
jamie
john
johnny
jamie
johnny
john
OP:
john
*/
