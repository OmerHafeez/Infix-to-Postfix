#include<iostream>
#include<stack>
using namespace std;

int getprecedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else if (op == '^')
		return 3;
	else
		return 0;
}

bool isoperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return true;
	return false;
 }

string infix_to_post(string infix)
{
	stack<char>s;
	string postfix;
	for (char ch: infix)
	{
		if (isalnum(ch))
			postfix += ch;
		else if (ch == '(')
			s.push(ch);
		else if (ch == ')')
		{
			while (!s.empty() && s.top() != ')')
			{
				postfix += ch;
				s.pop();
			}
			s.pop();
		}
		else if (isoperator(ch))
		{
			while (!s.empty() && getprecedence(ch) < getprecedence(s.top()))
			{
				postfix += ch;
				s.pop();
			}
		}

	}
	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

int main()
{
	string infix;
	cout<<"Enter the string : "<<endl;
	getline(cin, infix);
	string postfix = infix_to_post(infix);
	cout << "The postfix expression is :" << endl;
	cout << postfix;
}