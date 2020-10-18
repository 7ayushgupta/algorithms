#include <bits/stdc++.h>
using namespace std;

bool compareInterval(const pair<int, int> i1, const pair<int, int> i2) 
{ 
    return (i1.first < i2.first); 
} 

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int, int> > intervals(n);
        
        int count=0;
        for(int i = 0; i<n; i++, count++)
        {
            
            cin>>intervals[count].first>>intervals[count].second;
        }
        
        sort(intervals.begin(), intervals.end(), compareInterval);
        
        stack<pair<int, int> > s;
        s.push(intervals[0]);
        
        for(int i=1; i<n;i++)
        {
           
            if(intervals[i].first>s.top().second)
                s.push(intervals[i]);
            else if (intervals[i].second>s.top().second)
            {
                s.top().second = intervals[i].second;
            }
        }
        
        vector <int> answer;
        while (!s.empty()) 
        { 
            answer.push_back(s.top().second);
            answer.push_back(s.top().first);
            s.pop(); 
        } 
        for (int i = answer.size()-1; i>=0; i--)
            cout<<answer[i]<<" ";
        cout<<endl;
    }
	return 0;
}