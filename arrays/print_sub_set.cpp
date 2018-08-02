#include <bits/stdc++.h>
using namespace std;

void print_subset(vector<int> arr)
{
  int n=arr.size();
  n=1<<n;
  for(int i=0;i<n;i++)
  {
    int j=1;
    int index=0;
    cout<<"Set :: "<< i+1<<endl;
    cout<<"{ ";
    while(j<=i)
    {
      if(j&i)
      {
        cout<<arr[index]<<" ";
      }
      j=j<<1;
      index++;
    }
    cout<<"}\n===========================================\n";
  }
}

main()
{
  /* BEWARE PRINTS ALL 10,48,576 SUBSETS HAHAHA!!! */
  vector<int> arr={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
  print_subset(arr);
}
