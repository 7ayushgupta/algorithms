#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	stack <char> st;

	for (int i = 0; i<str.length(); i++)
		st.push(str[i]);

	string result;

	while(st.empty()!=true)
	{
		result+=st.top();
		st.pop();
	}

	cout<<result<<endl;
}