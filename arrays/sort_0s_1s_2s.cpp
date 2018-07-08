#include <iostream>
using namespace std;
void swap(int &i,int &j)
{
  int t=i;
  i=j;
  j=t;
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
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        switch (arr[mid])
        {
          case 0: swap(arr[low++],arr[mid++]);
                  break;
          case 1: mid++;
                  break;
          case 2: swap(arr[mid],arr[high--]);
                  break;
        }
    }
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
  }
}
