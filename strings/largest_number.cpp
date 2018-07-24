#include <bits/stdc++.h>
using namespace std;
bool mycmp(string a,string b)
{
  string ab=a.append(b);
  string ba=b.append(a);
  return ab>ba?1:0;
}
main()
{
  vector<string> arr;
  arr.push_back("54");
  arr.push_back("546");
  arr.push_back("548");
  arr.push_back("60");
  sort(arr.begin(),arr.end(),mycmp);
  for(int i=0;i<arr.size();i++)
    cout<<arr[i];
  cout<<endl;
}
