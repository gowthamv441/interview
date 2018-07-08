#include <bits/stdc++.h>
using namespace std;
void find_subarray(int arr[],int n,int sum)
{
  unordered_map<int,int> mp;
  int curr_sum=0;
  for(int i=0;i<n;i++)
  {
    curr_sum+=arr[i];
    if(curr_sum==sum)
    {
      cout<<1<<" "<<i+1<<endl;
      return;
    }
    else if(mp.find(curr_sum-sum)!=mp.end())
    {
      cout<<mp[curr_sum-sum]+2<<" "<<i+1<<endl;
      return;
    }
    mp[curr_sum]=i;
  }
  cout<<-1<<endl;
}
main()
{
  int test_case;
  cin>>test_case;
  for(int t=1;t<=test_case;t++)
  {
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    find_subarray(arr,n,sum);
  }
}
