/*
You are given two strings S1 and S2. S2 contains a ‘*’ in middle not at start or end.Now the ‘*’ can be replaced by a NULL character or any other substring from s1.You need to return the number of strings from s2 that are substrigs of s1. Ex-
s1 “aaabbaaabb”
s2 “aa*b”
Ans – 12(Count every occurrence of “aa” matching with a following “b” and sum them all you will get 12)

*/
#include <bits/stdc++.h>
using namespace std;
main()
{
  string s="aaabbaaabb";
  string sub1="aa",sub2="b";
  set<int> first_half_index;
  set<int> second_half_index;
  int pos=0;
  while(pos<s.length())
  {
    if(pos+sub1.length()<s.length()-1)/*because 0 based indexing*/
    {
      cout<<s.find(sub1,pos)<<endl;
      first_half_index.insert(s.find(sub1,pos));
      pos+=1;
    }
    else
      break;
  }
  cout<<"\n---------------\n";
  set<int> :: iterator it;
  int count=0;
  for(it=first_half_index.begin();it!=first_half_index.end();it++)
  {
    int pos=*it;
    while(pos<s.length())
    {
      if(pos+sub2.length()<s.length()-1)
      {
        cout<<s.find(sub2,pos)<<endl;
        second_half_index.insert(s.find(sub2,pos));
        pos+=1;
      }
      else
        break;
    }
    count+=second_half_index.size();
  }
  cout<<count<<endl;

}
