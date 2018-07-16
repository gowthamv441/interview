#include <bits/stdc++.h>
using namespace std;
int largest_area(int arr[])
{
  stack<int> s;
  int max_area=0;
  int i=0;
  while(i<4)
  {
    if(s.empty()||arr[s.top()]<arr[i])
    {
      s.push(i++);
    }
    else
    {
      int curr_max=s.top();
      s.pop();
      int area=arr[curr_max]*(s.empty()?i:i-s.top()-1);
      max_area=max(max_area,area);
    }
  }
  while(!s.empty())
  {
    int curr_max=s.top();
    s.pop();
    int area=arr[curr_max]*(s.empty()?i:i-s.top()-1);
    max_area=max(max_area,area);
  }
  return max_area;
}
int maximum_rectangle(int A[][4])
{
  int max_area=largest_area(A[0]);
  for(int i=1;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      if(A[i][j]==1)/*important*/
        A[i][j]+=A[i-1][j];
    }
    /*important*/
    max_area=max(max_area,largest_area(A[i]));
  }
  return max_area;
}
main()
{
  int A[][4] = { {0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0},
                 };
  cout<<maximum_rectangle(A)<<endl;
}
