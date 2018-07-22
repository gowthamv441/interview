#include <bits/stdc++.h>
using namespace std;
bool subset_sum(vector<int> arr,int sum)
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
  return mat[n][sum];
}
main()
{
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
      cin>>arr[i];
    cout<<subset_sum(arr,sum)<<endl;
  }
}
