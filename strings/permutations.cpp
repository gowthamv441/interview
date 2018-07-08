/* time complexity O(n*n!) */
#include <bits/stdc++.h>
using namespace std;

void swap(string &s,int l,int r)
{
  char t=s[l];
  s[l]=s[r];
  s[r]=t;
}
void reverse(string &s,int l,int h)
{
  while(l<h)
  {
    swap(s,l,h);
    l++;
    h--;
  }
}
bool next_permutation(string &s)
{
  int n=s.length()-1;
  int i,j;
  for(i=n-1;i>=0;i--)
  {
    if(s[i]<s[i+1])
      break;
  }
  if(i==-1)
    return false;
  for(j=n;j>i;j--)
  {
    if(s[j]>s[i])
      break;
  }
  swap(s,i,j);
  reverse(s,i+1,n);
  return true;
}
void permute(string &s)
{
  do {
    cout<<s<<" ";
  } while(next_permutation(s));
}
void sort(string &s,int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i]<s[j])
        swap(s,i,j);
    }
  }
}
main()
{
  int test_case;
  cin>>test_case;
  for(int t=1;t<=test_case;t++)
  {
    string s;
    cin>>s;
    int n=s.length();
    sort(s,n);
    permute(s);
    cout<<endl;
  }
}
