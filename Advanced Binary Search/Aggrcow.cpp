/*
https://www.spoj.com/problems/AGGRCOW/cstart=130
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool is_possible(vector<ll> arr,ll mid,int c)
{
  int pos=0;
  for(int i=1;i<arr.size();i++)
  {
    if(arr[i]-arr[pos]>=mid)
    {
      pos=i;
      c--;
    }
    if(c==1)
      return true;
  }
  return false;
}
ll binary_search(vector<ll> arr,int c)
{
  int l=0;
  int r=arr[arr.size()-1];
  ll max=0;
  while(l<r)
  {
    ll mid=(l+r)/2;
    if(is_possible(arr,mid,c))
    {
      if(mid>max)
        max=mid;
      l=mid+1;
    }
    else
    {
      r=mid;
    }
  }
  return max;
}
int main()
{
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    int n,c;
    cin>>n>>c;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<binary_search(arr,c)<<endl;
  }
  return 0;
}
