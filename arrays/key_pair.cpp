#include <bits/stdc++.h>
using namespace std;
bool key_pair(int arr[],int n,int x)
{
  int l=0;
  int r=n-1;
  while(l<r)
  {
    if(arr[l]+arr[r]==x)
      return true;
    else if(arr[l]+arr[r]>x)
      r--;
    else if(arr[l]+arr[r]<x)
      l++;
  }
  return false;
}
main()
{
  int test_case;
  cin>>test_case;
  for(int t=1;t<=test_case;t++)
  {
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    sort(arr,arr+n);
    if(key_pair(arr,n,x))
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
}
