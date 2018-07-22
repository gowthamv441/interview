/*
https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int mat[100][100];
int dp[100][100];
int compute_distance(int i,int j)
{
  if(i<0||i>n||j<0||j>n)
    return 0;
  if(dp[i][j]!=-1)
    return dp[i][j];
  //left
  if(j-1>=0&&(mat[i][j]+1)==mat[i][j-1])
  {
    return dp[i][j]=1+compute_distance(i,j-1);
  }
  //top
  if(i-1>=0&&(mat[i][j]+1)==mat[i-1][j])
  {
    return dp[i][j]=1+compute_distance(i-1,j);
  }
  //right
  if(j+1<n&&(mat[i][j]+1)==mat[i][j+1])
  {
    return dp[i][j]=1+compute_distance(i,j+1);
  }
  //bottom
  if(i+1<n&&(mat[i][j]+1)==mat[i+1][j])
  {
    return dp[i][j]=1+compute_distance(i+1,j);
  }
  // if not possible to go in four direction;
  return dp[i][j]=1;
}
main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>mat[i][j];
      dp[i][j]=-1;
    }
  }
  int max_dist=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(dp[i][j]==-1)
      {
          compute_distance(i,j);
      }
      max_dist=max(max_dist,dp[i][j]);
    }
  }
  cout<<max_dist<<endl;
}
