/*
https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
*/

#include <bits/stdc++.h>
using namespace std;
int count_ways(vector<int> coins,int val)
{
  int dp[val+1]={0};
  dp[0]=1;

  for(int i=0;i<coins.size();i++)
    for(int j=coins[i];j<=val;j++)
      dp[j]+=dp[j-coins[i]];

  return dp[val];
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0;i<n;i++)
      cin>>coins[i];
    int val;
    cin>>val;
    cout<<count_ways(coins,val)<<endl;
  }
}
