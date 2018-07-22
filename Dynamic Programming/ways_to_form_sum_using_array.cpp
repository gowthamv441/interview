/*
https://www.geeksforgeeks.org/ways-sum-n-using-array-elements-repetition-allowed/
*/
#include <bits/stdc++.h>
using namespace std;
int count_ways(vector<int> arr,int sum)
{
  int dp[sum+1]={0};
  dp[0]=1;
  for(int i=1;i<=sum;i++)
  {
    for(int j=0;j<arr.size();j++)
    {
      if(arr[j]<=i)
      {
        dp[i]+=dp[i-arr[j]];
      }
    }
  }
  return dp[sum];
}
main()
{
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int sum;
    cin>>sum;
    cout<<count_ways(arr,sum)<<endl;
  }
}
