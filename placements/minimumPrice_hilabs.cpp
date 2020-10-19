#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, x;
	cin>>N>>x;
	vector<int> arr(N);
	for(int i = 0; i<N;i++)	
	    cin>>arr[i];
	vector<int> minimumRots(N, 0);
	int total_cost = 0;
	for(int i = 0; i<N; i++)
	{
		int cost = INT_MAX;
		int rots_min = N;
		for(int j = 0; j<N; j++)
		{
			int num_rots;
			if(j>i)
				num_rots = N-j+i;
			else
				num_rots = i-j;
			int new_cost = x*(num_rots) + arr[j];
			
			if (new_cost<cost)
			{
				cost = new_cost;
				rots_min = num_rots;
			}
		}
		minimumRots[i] = rots_min;
		total_cost+=(cost - x*rots_min);
	}
	int rotations = INT_MIN;
	for(int i = 0; i<N; i++)
	   rotations = max(rotations, minimumRots[i]);
	   
	for(int i = 0; i<N; i++) cout<< minimumRots[i] << " "; cout<<endl;
	total_cost+= rotations*x;
	cout<<total_cost<<endl;
}