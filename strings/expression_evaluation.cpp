#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
  if(op=='+'||op=='-')
    return 1;
  if(op=='*'||op=='/')
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
int evaluate(string s)
{
  stack<int> values;
  stack<char> ops;
  int i;
  for(i=0;i<s.length();i++)
  {
    /* if space continue*/
    if(s[i]==' ')
      continue;

    /* if open braces push it to stack*/
    else if(s[i]=='(')
      ops.push(s[i]);

    /* if curr char is digit make it as a integer and push to stack*/
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

    /*if curr char is close braces pop values and operator and perform
      operation*/
    else if(s[i]==')')
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
      ops.pop();
    }

    /* if it is a operator pop and perform operation
     based on precedence*/
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
  cout<<evaluate("2 * 6")<<endl;
}
