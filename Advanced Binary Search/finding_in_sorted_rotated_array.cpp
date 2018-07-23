#include <iostream>
using namespace std;
int find_element(int arr[],int x,int l,int r)
{
  if(l>r)
    return -1;
  int mid=(l+r)>>1;
  if(arr[mid]==x)
    return mid;
  if(arr[l]<=arr[mid])
  {
    if(x>=arr[l]&&x<=arr[mid])
      return find_element(arr,x,l,mid-1);
    return find_element(arr,x,mid+1,r);
  }
  if(x>=arr[mid]&&x<=arr[r])
    return find_element(arr,x,mid+1,r);
  return find_element(arr,x,l,mid-1);
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
    int x;
    cin>>x;
    cout<<find_element(arr,x,0,n-1)<<endl;
  }
}
