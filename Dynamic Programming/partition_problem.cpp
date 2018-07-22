/*
https://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
*/
#include <bits/stdc++.h>
using namespace std;
bool is_patition_possible(vector<int> arr,int sum)
{
  int n=arr.size();
  bool dp[n+1][sum+1];
  for(int i=0;i<=n;i++)
    dp[i][0]=true;
  for(int i=1;i<=sum;i++)
    dp[0][i]=false;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      dp[i][j]=dp[i-1][j];
      if(arr[i-1]<=j)
        dp[i][j]|=dp[i-1][j-arr[i-1]];
    }
  }
  return dp[n][sum];
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      sum+=arr[i];
    }
    if(sum&1)
      cout<<"Not Possible to split"<<endl;
    else if(is_patition_possible(arr,sum/2))
      cout<<"Yes Possible to split"<<endl;
    else
      cout<<"Not Possible to split"<<endl;
  }
}
