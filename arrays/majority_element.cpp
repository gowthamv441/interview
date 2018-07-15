#include <iostream>
using namespace std;
int find_candidate(int arr[],int n)
{
  int count=1,maj_index=0;
  for(int i=1;i<n;i++)
  {
    if(arr[maj_index]==arr[i])
      count++;
    else
      count--;
    if(count==0)
    {
      maj_index=i;
      count=1;
    }
  }
  return arr[maj_index];
}
bool is_majority(int cand,int arr[],int n)
{
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]==cand)
      count++;
  }
  if(count>n/2)
    return true;
  return false;
}
int find_majority_element(int arr[],int n)
{
  int cand=find_candidate(arr,n);
  if(is_majority(cand,arr,n))
    return cand;
  else
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
      cin>>arr[i];
    int ans=find_majority_element(arr,n);
    if(ans==-1)
      cout<<"NO Majority Element"<<endl;
    else
      cout<<ans<<endl;
  }
}
