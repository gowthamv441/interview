#include <bits/stdc++.h>
using namespace std;
void compute_lps(int lps[],int n,string pat)
{
  int len=0;
  int i=1;
  lps[0]=0;
  while(i<n)
  {
    if(pat[i]==pat[len])
    {
      len++;
      lps[i]=len;
      i++;
    }
    else
    {
      if(len!=0)
      {
        len=lps[len-1];
      }
      else
      {
        lps[i]=0;
        i++;
      }
    }
  }
}
void kmp(string text,string pat)
{
  int m=text.length();
  int n=pat.length();
  int lps[n];
  compute_lps(lps,n,pat);

  int i=0;
  int j=0;
  while(i<m)
  {
    if(text[i]==pat[j])
    {
      i++;
      j++;
    }
    if(j==n)
    {
      cout<<"pattern found at "<<i-j<<endl;
      j=lps[j-1];
    }
    else if(i<m&&text[i]!=pat[j])
    {
      if(j!=0)
        j=lps[j-1];
      else
        i=i+1;
    }
  }

}
main()
{
  string text,pat;
  cin>>text>>pat;
  kmp(text,pat);
}
