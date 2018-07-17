#include <bits/stdc++.h>
using namespace std;
int find_range_sum(vector<int> Prefix_Sum,int l,int r)
{
  if(l>0)
    return Prefix_Sum[r]-Prefix_Sum[l-1];
  return Prefix_Sum[r];
}
main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];

  vector<int> Prefix_Sum(n);
  Prefix_Sum[0]=arr[0];
  for(int i=1;i<n;i++)
    Prefix_Sum[i]=Prefix_Sum[i-1]+arr[i];
  int queries;
  cin>>queries;
  /*ranges are 0 based indexing*/
  while (queries--) {
    int l,r;
    cin>>l>>r;
    cout<<find_range_sum(Prefix_Sum,l,r)<<endl;
  }
}
