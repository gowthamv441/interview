/*
Input:
 abcabcabc
Output:
 true
Because abc substring is repeated 3 times to form the string;
*/
#include <iostream>
using namespace std;
bool find_lps(string s)
{
    int lps[s.length()];
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<s.length())
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    int res=lps[s.length()-1];
    int n=s.length();
    // cout<<n/(n-len)<<endl; (repeat count) 
    return (res>0&&n%(n-len)==0)?true:false;
}
int main() {
	int test_case;
	cin>>test_case;
	while(test_case--)
	{
	    string s;
	    cin>>s;
	    if(find_lps(s))
	        cout<<"True"<<endl;
	    else
	        cout<<"False"<<endl;
	}
	return 0;
}
