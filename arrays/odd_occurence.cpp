#include <iostream>
using namespace std;
int find_odd_occurence(int arr[],int n)
{
  int x=arr[0];
  for(int i=1;i<n;i++)
  {
    x=x^arr[i];
  }
  return x;
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
      cin>>arr[i];
    cout<<find_odd_occurence(arr,n)<<endl;
  }
}
