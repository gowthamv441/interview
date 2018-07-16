#include <bits/stdc++.h>
using namespace std;
/*
Algorithm:
  -Push it to stack when stack empty or curr bar is higher than stack.top

  -when curr bar is lesser than stack.top

    -pick the stack.top and find area that it could until next stack.top()

    -if stack empty then it is the smallest element so multiply with index

  -after the end of the arr we some elements remaining in stack pop that
    from stack and find the area and update max area;

  -return max_area
*/
int find_max_area(vector<int> arr)
{
  stack<int> s;
  int max_area=0;
  int i=0;
  while(i<arr.size())
  {
    if(s.empty()||arr[s.top()]<=arr[i])
    {
      s.push(i);
      i++;
    }
    else
    {
      int curr_max=s.top();
      s.pop();
      int area=arr[curr_max]*(s.empty()?i:i-s.top()-1);/*(-1) because s.top() will be less than i so the range would be i-s.top()-1 */
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
main()
{
  vector<int> arr={1,2,3,4,5,3,3,2};
  cout<<find_max_area(arr)<<endl;
}
