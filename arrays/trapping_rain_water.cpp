#include <iostream>
using namespace std;
int find_water_amount(int arr[],int n)
{
  int left_bar[n],right_bars[n];
  int water=0;

  /*store max height till now from left*/
  left_bar[0]=arr[0];
  for(int i=1;i<n;i++)
    left_bar[i]=max(left_bar[i-1],arr[i]);

  /*store max height till now from right*/
  right_bars[n-1]=arr[n-1];
  for(int i=n-2;i>=0;i--)
    right_bars[i]=max(right_bars[i+1],arr[i]);

  // Calculate the accumulated water element by element
  // consider the amount of water on i'th bar, the
  // amount of water accumulated on this particular
  // bar will be equal to min(left[i], right[i]) - arr[i]
  for(int i=0;i<n;i++)
  {
    water+=min(left_bar[i],right_bars[i])-arr[i];
  }
  return water;
}
main()
{
  int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<find_water_amount(arr,n)<<endl;
}
