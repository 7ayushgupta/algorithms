#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int catalan[n+1]={0};
		catalan[0]=1;
		catalan[1]=1;
		for(int i = 2; i<=n; i++)
			for(int j = 0; j<i; j++)
				catalan[i]+=catalan[j]*catalan[i-j-1];
		cout<<catalan[n]<<endl;
	}
}