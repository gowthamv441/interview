/*
https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
*/

#include <bits/stdc++.h>
using namespace std;
int subset_partition_min_diff(vector<int> arr,int sum)
{
  int n=arr.size();
  int mat[n+1][sum+1];
  for(int i=0;i<=n;i++)
    mat[i][0]=true;
  for(int i=1;i<=sum;i++)
    mat[0][i]=false;

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      mat[i][j]=mat[i-1][j];
      if(j>=arr[i-1])
        mat[i][j]|=mat[i-1][j-arr[i-1]];
    }
  }
  for(int j=sum/2;j>=0;j--)
  {
      if(mat[n][j])
      {
        return sum-(2*j);
      }
  }
  return -1;
}
main()
{
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      sum+=arr[i];
    }
    cout<<subset_partition_min_diff(arr,sum)<<endl;
  }
}
