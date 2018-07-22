#include <bits/stdc++.h>
using namespace std;
int edit_distance(string s1,string s2)
{
  int m=s1.length();
  int n=s2.length();
  int mat[m+1][n+1];
  for(int i=0;i<n;i++)
    mat[0][i]=i;
  for(int i=0;i<m;i++)
    mat[i][0]=i;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(s1[i-1]==s2[j-1])
        mat[i][j]=mat[i-1][j-1];
      else
        mat[i][j]=min(mat[i-1][j],min(mat[i][j-1],mat[i-1][j-1]))+1;
    }
  }
  return mat[m][n];
}
main()
{
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    string s1,s2;
    cin>>s1>>s2;
    cout<<edit_distance(s1,s2)<<endl;
  }
}
