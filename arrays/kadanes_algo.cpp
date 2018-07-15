#include <iostream>
using namespace std;
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

    int max_so_for=INT_MIN;
    int curr_max=0;
    int s=0,start,end;
    for(int i=0;i<n;i++)
    {
      curr_max+=arr[i];
      if(max_so_for<curr_max)
      {
        start=s;
        end=i;
        max_so_for=curr_max;
      }
      if(curr_max<0)
      {
        curr_max=0;
        s=i+1;
      }
    }
    cout<<"#case"<<t<<" "<<max_so_for<<" "<<start<<" "<<end<<endl;
  }
}
