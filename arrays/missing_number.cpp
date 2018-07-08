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
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
      cin>>arr[i];
      sum+=arr[i];
    }
    int total_sum=(n*(n+1))/2;
    cout<<"#"<<t<<" "<<(total_sum-sum)<<endl;
  }
}
