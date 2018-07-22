/*
https://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
*/
#include <bits/stdc++.h>
using namespace std;
int find_max_price(vector<int> price)
{
  int n=price.size();
  int dp[n+1]={0};
  for(int i=1;i<=n;i++)
  {
    int max_price=INT_MIN;
    for(int j=0;j<i;j++)
    {
      max_price=max(max_price,price[j]+dp[i-j-1]);
    }
    dp[i]=max_price;
  }
  return dp[n];
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i=0;i<n;i++)
      cin>>price[i];
    cout<<find_max_price(price)<<endl;
  }
}
