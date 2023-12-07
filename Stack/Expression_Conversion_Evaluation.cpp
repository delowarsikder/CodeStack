#include <bits/stdc++.h>
using namespace std;

#define FastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);

#define clearBuffer cin.ignore(numeric_limits<streamsize>::max(), '\n')

bool isOperator(char ch)
{
  if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^')
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isOpearand(char ch)
{
  if (ch >= '0' && ch <= '9')
  {
    return true;
  }
  else
  {
    return false;
  }
}

int precedence(char ch)
{
  if (ch == '+' || ch == '-')
  {
    return 1;
  }
  else if (ch == '*' || ch == '/')
  {
    return 2;
  }
  else if (ch == '^')
  {
    return 3;
  }
  else
  {
    return -1;
  }
}

void print(string str)
{
  cout << str << endl;
}

string infix2postfix(string str)
{
  stack<char> stack;
  stack.push('(');
  str = str + ')';
  string postfix = "";

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == ' ' || str[i] == ',')
    {
      continue;
    }
    else if (isOpearand(str[i]))
    {
      string temp = "";
      while (isOpearand(str[i]) && i < str.length())
      {
        temp = temp + str[i];
        i++;
      }
      i--;
      postfix = postfix + ' ' + temp;
    }
    else if (isOperator(str[i]))
    {
      while (!stack.empty() && (precedence(stack.top()) > precedence(str[i])))
      {
        postfix = postfix + ' ' + stack.top();
        stack.pop();
      }
      stack.push(str[i]);
    }

    else if (str[i] == '(')
    {
      stack.push(str[i]);
    }
    else if (str[i] == ')')
    {
      while (stack.top() != '(' && !stack.empty())
      {
        postfix = postfix + ' ' + stack.top();
        stack.pop();
      }
      stack.pop();
    }
  }
  while (!stack.empty())
  {
    postfix = postfix + ' ' + stack.top();
    stack.pop();
  }
  return postfix;
}

string infix2prefix(string str)
{
  reverse(str.begin(), str.end());
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '(')
    {
      str[i] = ')';
    }
    else if (str[i] == ')')
    {
      str[i] = '(';
    }
  }
  string prefix = infix2postfix(str);
  reverse(prefix.begin(), prefix.end());
  return prefix;
}

double evaluation(char op, double x, double y)
{
  switch (op)
  {
  case '+':
    return x + y;
    break;
  case '-':
    return x - y;
    break;
  case '*':
    return x * y;
    break;
  case '/':
    return x / y;
    break;
  case '^':
    return int(x) ^ int(y);
    break;
  default:
    return 0;
    break;
  }
}

void evaluationPostfix(string str)
{
  stack<double> result;
   double ans=0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == ' ' || str[i] == ',')
    {
      continue;
    }
    else if (isOpearand(str[i]))
    {
      double temp = 0;
      while (i < str.length() && isOpearand(str[i]))
      {
        double val = str[i] - '0';
        temp = temp * 10 + val;
        i++;
      }
      result.push(temp);
      i--;
    }
    else if (isOperator(str[i]))
    {
      double op1 = result.top();
      result.pop();
      double op2 = result.top();
      result.pop();
      ans = evaluation(str[i], op2, op1); 
      result.push(ans);
    }
  }
  cout << "Result : " << ans << endl;
}

int main()
{
  FastIO;
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  string infix;
  getline(cin, infix);
  cout << "infix  : ";
  print(infix);
  string postfix = infix2postfix(infix);
  cout << "postfix: ";
  print(postfix);
  infix2prefix(infix);
  string prefix = infix2prefix(infix);
  cout << "prefix : ";
  print(prefix);
  evaluationPostfix(postfix);

  return 0;
}
