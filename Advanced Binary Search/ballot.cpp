/*
https://www.spoj.com/problems/BALLOT/
*/
#include <bits/stdc++.h>
using namespace std;
bool is_possible(vector<int> arr,int mid,int b)
{
  for(int i=0;i<arr.size();i++)
  {
    b-=ceil(float(arr[i])/float(mid));
  }
  if(b>=0)
    return true;
  else
    return false;
}
int binary_search(vector<int> arr,int b)
{
  int l=0;
  int r=arr[arr.size()-1];
  int max=INT_MAX;
  while(l<r)
  {
    int mid=(l+r)/2;
    if(is_possible(arr,mid,b))
    {
      if(mid<max)
        max=mid;
      r=mid;
    }
    else
      l=mid+1;
  }
  return max;
}
int main()
{
  int n,b;
  cin>>n>>b;
  while(n!=-1&&b!=-1)
  {
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<binary_search(arr,b)<<endl;
    cin>>n>>b;
  }
  return 0;
}
