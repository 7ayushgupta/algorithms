#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> nums(n+1);
	for(int i = 0; i<n; i++)
		cin>>nums[i+1];
	bool flag=false;
	for(int i = 1; i<n+1 && !(flag); i++)
		if(nums[nums[nums[i]]]==i)
			flag=true;
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}