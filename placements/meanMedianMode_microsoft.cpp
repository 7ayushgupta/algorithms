#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i<n;i++)	
	    cin>>arr[i];
	int sum = 0;
	for(int i = 0; i<n; i++)
		sum+=arr[i];
	int mean = sum/n;

	unordered_map<int, int> hash;
	for(int i = 0; i<n; i++)
		hash[arr[i]]++;

	int max_count = 0, mode = -1;
	for(auto i: hash){
		if(max_count<i.second){
			mode = i.first;
			max_count = i.second;
		}
	}

 	int median = 0;
	if(n%2==0)
	{
		nth_element(arr.begin(), arr.begin()+(n/2)+1, arr.begin()+n);
		median = arr[(n/2)]+arr[(n/2)+1];
	}
	else
	{
		nth_element(arr.begin(), arr.begin()+(n/2)+1, arr.begin()+n);
		median = arr[(n/2)];
	}

	cout<<mean<<" "<<median<<" "<<mode<<endl;
	
}