#include <bits/stdc++.h>
using namespace std;
int invert_bits(int n)
{
  int x=log2(n)+1;
  for(int i=0;i<x;i++)
  {
    n=n^(1<<i);
  }
  return n;
}
/*
time complexity : O(log n)
space complexity: O(1)
void invertBits(int num)
{
    // calculating number of bits
    // in the number
    int x = log2(num) + 1;

    // Considering number to be 32 bit integer;
    bitset<32> b(num);

    // reversing the bits one by one
    for (int i = 0; i < x; i++)
        b.flip(i);

    // converting bitset to number
    cout << b.to_ulong();
}
*/
main()
{
  int n;
  cin>>n;
  cout<<invert_bits(n)<<endl;
}
