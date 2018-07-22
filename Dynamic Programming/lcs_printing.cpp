#include <bits/stdc++.h>
using namespace std;
void LCS(string s1,string s2)
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
  // Common sequence printing
  int index=lcs[m][n];
  char s[index+1];
  s[index--]='\0';
  int i=m,j=n;
  while(i>0&&j>0)
  {
    if(s1[i-1]==s2[j-1])
    {
      s[index--]=s1[i-1];
      i--;j--;
    }
    else if(lcs[i-1][j]>lcs[i][j-1])
      i--;
    else
      j--;
  }
  cout<<"Common subsequence "<<s<<endl;

  //Merge two strings
  index=n+m;
  char *ans;
  i=m,j=n;
  int k=0;
  while(i>0&&j>0)
  {
    if(s1[i-1]==s2[j-1])
    {
      ans[k++]=s1[i-1];
      i--;
      j--;
    }
    else if(lcs[i-1][j]>lcs[i][j-1])
    {
      ans[k++]=s1[i-1];
      i--;
    }
    else
    {
      ans[k++]=s2[j-1];
      j--;
    }
  }
  while(i>0)
  {
    ans[k++]=s1[i-1];
    i--;
  }
  while (j>0) {
    ans[k++]=s2[j-1];
    j--;
  }
  ans=strrev(ans);
  cout<<"Merged string "<<ans<<endl;
}
main()
{
  int test_case;
  cin>>test_case;
  while(test_case--)
  {
    string str1,str2;
    cin>>str1>>str2;
    LCS(str1,str2);
  }
}
