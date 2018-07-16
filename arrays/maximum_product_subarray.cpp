#include <bits/stdc++.h>

using namespace std;
int maximum(int a,int b,int c)
{
	return max(a,max(b,c));
}

int minimum(int a,int b,int c)
{
	return min(a,min(b,c));
}
int findMaxProduct(int a[], int n)
{
	int prev_max=a[0];
	int prev_min=a[0];
	int ans=a[0];
	for (int i = 1; i < n; i++)
	{
		int curr_max=maximum(prev_max*a[i],prev_min*a[i],a[i]);
		int curr_min=minimum(prev_max*a[i],prev_min*a[i],a[i]);
		ans=max(ans,curr_max);
		prev_max=curr_max;
		prev_min=curr_min;
	}
	return ans;
}

int main()
{
	int arr[] = { 0, -4, 0, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findMaxProduct(arr, n);
	return 0;
}
