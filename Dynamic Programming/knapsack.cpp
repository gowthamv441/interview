/*
https://www.geeksforgeeks.org/knapsack-problem/
*/
#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> val,vector<int> wt,int capacity)
{
  int n=wt.size();
  int dp[n+1][capacity+1];

  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=capacity;j++)
    {
      if(i==0||j==0)
        dp[i][j]=0;
      else if(wt[i-1]<=j)
        dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i-1]]);
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  return dp[n][capacity];
}
main()
{
  int n;
  cin>>n;
  vector<int> val(n);
  vector<int> wt(n);
  for(int i=0;i<n;i++)
    cin>>val[i];
  for(int i=0;i<n;i++)
    cin>>wt[i];
  int capacity;
  cin>>capacity;
  cout<<knapsack(val,wt,capacity)<<endl;
}
