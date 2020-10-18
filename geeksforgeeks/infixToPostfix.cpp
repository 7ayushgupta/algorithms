#include <bits/stdc++.h>
using namespace std;

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
bool isOperand(char character)
{
	if (character >= 'a' && character <= 'z')
		return true;
	else
		return false;
}

void infixToPostfix(string str)
{
	int n = str.length();
	stack <char> s;
	s.push('N');
	string answer="";

	for (int  i = 0; i<n; i++)
	{
		char current_character = str[i];

		if (isOperand(current_character))
			answer.push_back(current_character);
		else if(current_character=='(')
			s.push(current_character);
		else if(current_character==')')
		{
			while(s.top()!='N' && s.top()!='(')
			{
				char c = s.top();
				s.pop();
				answer+=c;
			}
			if(s.top() == '(')
			{
				char c = s.top();
				s.pop();
			}
		}
		else
		{
			while(s.top()!='N' & prec(current_character)<=prec(s.top()))
			{
				char c = s.top();
				s.pop();
				answer+=c;
			}
			s.push(current_character);
		}
	}
	while(s.top()!='N')
	{
		char c = s.top();
		s.pop();
		answer+=c;
	}
	cout<<answer<<endl;
}


int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixToPostfix(exp); 
    return 0; 
}