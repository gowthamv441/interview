#include <bits/stdc++.h>
using namespace std;
void Running_median(vector<int> arr)
{
  //max_heap for smaller half
  priority_queue< int,vector<int> > s;
  //min_heap for greater half
  priority_queue< int, vector<int>, greater<int> > g;
  s.push(arr[0]);
  cout<<double(arr[0])<<endl;

  for(int i=1;i<arr.size();i++)
  {
    int x=arr[i];
    if(s.size()>g.size())
    {
      if(x<s.top())
      {
        g.push(s.top());
        s.pop();
        s.push(x);
      }
      else
        g.push(x);
      cout<<(double(s.top())+double(g.top()))/2.0<<endl;
    }
    else if(s.size()==g.size())
    {
      if(x<s.top())
      {
        s.push(x);
        cout<<double(s.top())<<endl;
      }
      else
      {
        g.push(x);
        cout<<double(g.top())<<endl;
      }
    }
    else
    {
      if(x>g.top())
      {
        s.push(g.top());
        g.pop();
        g.push(x);
      }
      else
        s.push(x);
      cout<<(double(s.top())+double(g.top()))/2.0<<endl;
    }
  }
}
main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  Running_median(arr);
}
