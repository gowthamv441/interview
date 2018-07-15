#include <bits/stdc++.h>
using namespace std;

int maximum_sum(int arr[],int n)
{
    int curr_max=0;
    int max_so_far=INT_MIN;
    int start,end,s=0;
    for(int i=0;i<n;i++)
    {
        curr_max+=arr[i];
        if(curr_max>max_so_far)
        {
            max_so_far=curr_max;
            start=s;
            end=i;
        }
        if(curr_max<0)
        {
            curr_max=0;
            s=i+1;
        }
    }
    cout<<start<<" "<<end<<endl;
    return max_so_far;
}
int main() {
    int test_case;
    cin>>test_case;
    for(int t=1;t<=test_case;t++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maximum_sum(arr,n)<<endl;
    }
	return 0;
}
