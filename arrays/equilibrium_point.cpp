#include <iostream>
using namespace std;
int equilibrium_point(int arr[],int n)
{
  int right_sum=0;
  int left_sum=0;
  for(int i=0;i<n;i++)
  {
    right_sum+=arr[i];
  }
  for(int i=0;i<n;i++)
  {
    right_sum-=arr[i];
    if(left_sum==right_sum)
    {
      return i+1; //1 based indexing
    }
    left_sum+=arr[i];
  }
  return -1;
}
main()
{
  int test_case;
  cin>>test_case;
  for(int t=1;t<=test_case;t++)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    cout<<equilibrium_point(arr,n)<<endl;
  }
}
