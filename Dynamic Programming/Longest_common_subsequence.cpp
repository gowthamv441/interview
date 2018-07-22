#include <bits/stdc++.h>
using namespace std;
int LCS(string s1,string s2)
{
  int m=s1.length();
  int n=s2.length();
  int lcs[m+1][n+1];
  for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
      if(i==0||j==0)
        lcs[i][j]=0;
      else if(s1[i-1]==s2[j-1])
        lcs[i][j]=lcs[i-1][j-1]+1;
      else
        lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
    }
  }
  return lcs[m][n];
}
main()
{
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    string str1,str2;
    cin>>str1>>str2;
    cout<<LCS(str1,str2)<<endl;
  }
}
