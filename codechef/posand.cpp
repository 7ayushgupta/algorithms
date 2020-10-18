#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        if(ceil(log2(n)) == floor(log2(n)))
        {
            cout<<"-1"<<endl;
            continue;
        }
        vector<int> answer;
        answer[0]=2;
        answer[1]=3;
        answer[2]=1;
        for(long long int i=3;i<n;i++)
        {
            if(floor(log2(i))==ceil(log2(i)))
                answer[i]=i;
            else if((floor(log2(i+1))==ceil(log2(i+1))))
                answer[i]=i+2;
            else
                answer[i]=i+1;
        }
        for(int i = 0; i<n; i++)
            cout<<answer[i]<<" ";
        cout<<endl;
    }
}