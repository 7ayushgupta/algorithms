#include <bits/stdc++.h>
using namespace std;

char convertToLowercase(char c)
{
	if(c>='A' && c<='Z')
		return c-'A'+'a';
	return c;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string input;
		cin>>input;
		string snake = "";
		snake+=convertToLowercase(input[0]);
		for(int i = 1; i<input.size(); i++)
		{
			char c = input[i];
			if(c>='A' && c<='Z')
			{
				snake+='_';
				snake+=convertToLowercase(c); 
			}
			else
				snake+=c; 
		}
		cout<<snake<<endl;
	}
}