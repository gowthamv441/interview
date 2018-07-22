/*
https://www.geeksforgeeks.org/dynamic-programming-set-36-cut-a-rope-to-maximize-product/
*/
#include <iostream>
using namespace std;
int max_product(int n)
{
  if(n==2||n==3) return n-1;
  int res=1;
  while(n>4)
  {
    n-=3;
    res*=3;
  }
  return n*res;
}
main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    cout<<max_product(n)<<endl;
  }
}
