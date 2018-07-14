#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
  if(op=='+'||op=='-')
    return 1;
  else if(op=='*'||op=='/')
    return 2;
  return 0;
}

int apply_operator(int a,int b,char op)
{
  switch(op)
  {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
  }
}
bool isdigit(char a)
{
  return a>='0'&&a<='9';
}
int evaluate(string s)
{
  stack<int> values;
  stack<char> ops;

  for(int i=0;i<s.length();i++)
  {
    cout<<s[i]<<" ";
    if(s[i]==' ')
      continue;
    else if(s[i]=='(')
      ops.push(s[i]);
    else if(isdigit(s[i]))
    {
      int val=0;
      while(i<s.length()&&isdigit(s[i]))
      {
        val=(val*10)+(s[i]-'0');
        i++;
      }
      values.push(val);
    }
    else if(s[i]=')')
    {
      while(!ops.empty()&ops.top()!='(')
      {
        int val2=values.top();
        values.pop();
        int val1=values.top();
        values.pop();
        char op=ops.top();
        ops.pop();
        values.push(apply_operator(val1,val2,op));
      }
      ops.top();
    }
    else
    {
      while(!ops.empty()&&precedence(s[i])<=precedence(ops.top()))
      {
        int val2=values.top();
        values.pop();
        int val1=values.top();
        values.pop();
        char op=ops.top();
        ops.pop();
        values.push(apply_operator(val1,val2,op));
      }
      ops.push(s[i]);
    }
  }
  while(!ops.empty())
  {
    int val2=values.top();
    values.pop();
    int val1=values.top();
    values.pop();
    char op=ops.top();
    ops.pop();
    values.push(apply_operator(val1,val2,op));
  }
  return values.top();
}
main()
{
  int test_case;
  cin>>test_case;
  for(int t=1;t<=test_case;t++)
  {
    string s;
    cin>>s;
    cout<<"#"<<t<<" "<<evaluate(s)<<endl;
  }

}
