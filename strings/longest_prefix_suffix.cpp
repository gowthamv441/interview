#include <iostream>
using namespace std;
int find_lps(string s)
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
    /* since we are looking for non overlapping parts */
    return (res>s.length()/2)?(s.length()/2):(res);
}
int main() {
	int test_case;
	cin>>test_case;
	while(test_case--)
	{
	    string s;
	    cin>>s;
	    cout<<find_lps(s)<<endl;
	}
	return 0;
}
