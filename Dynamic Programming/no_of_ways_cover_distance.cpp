/*
https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/
*/

#include <iostream>
using namespace std;
int count_ways(int n)
{
  if(n==0||n==1)
    return 1;
  if(n==2)
    return 2;
  int a=1,b=1,c=2;
  int ans=0;
  for(int i=3;i<=n;i++)
  {
      ans=a+b+c;
      a=b;
      b=c;
      c=ans;
  }
  return ans;
}
main()
{
  int n;
  cin>>n;
  cout<<count_ways(n)<<endl;
}
