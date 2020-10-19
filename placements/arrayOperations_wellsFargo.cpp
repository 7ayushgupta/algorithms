// Given an array arr containing positive elements and an integer K. In one operation you can pick an element of the array (suppose arr[i]) & break to p1,p2 insert p1 & p2. You need to find the minimum possible value.
#include <bits/stdc++.h> 
using namespace std;

int count_elt(int x, int target)
{
	if (x==0)
		return 0;
	int count = x/target;
    if (target*count == x) count --;
    return count;
}

bool check_target(vector<int> A, int K, int target)
{
	int n = A.size();
	int count  = 0;
	for(int val: A)
	{
		if((val<=target) || count>K)
			break;
		count+=count_elt(val, target);
	}
	return count<=K;
}


int minmax(vector<int> A, int K)
{
	sort(A.begin(), A.end(), greater<int>());
	if(A[0]==0) return 0;
	int limit_0 = 0;
	int limit_1 = A[0];
	while(true)
	{
		if(limit_1==limit_0+1)
			return limit_1;
		int target = (limit_1+limit_0)/2;
		if(check_target(A, K, target))
			limit_1=target;
		else
			limit_0 = target;
	}
	return -1;
}

int main()
{
	vector<int> A = {12,3,3,9};
	int K = 3;
	int count = minmax(A, K);
	cout<<count<<endl;
}