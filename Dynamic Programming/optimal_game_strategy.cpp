/*
https://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/
*/
#include <bits/stdc++.h>
using namespace std;
int max_coins(vector<int> arr)
{
  int n=arr.size();
  int dp[n][n];

  for(int gap=0;gap<n;gap++)
  {
    for(int i=0,j=gap;j<n;i++,j++)
    {
      int x= (i+2<=j)?dp[i+2][j]:0;
      int y= (i<=j-2)?dp[i][j-2]:0;
      int z= (i+1<=j+1)?dp[i+1][j+1]:0;

      dp[i][j]=max(arr[i]+min(x,z),arr[j]+min(y,z));
    }
  }
  return dp[0][n-1];
}
main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<max_coins(arr)<<endl;
}
