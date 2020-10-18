#include <bits/stdc++.h>
using namespace std;

int test_case(int n)
{
    if(ceil(log2(n)) == floor(log2(n)))
    {
        cout<<"-1"<<endl;
        return -1;
    }
    vector<int> answer;
    int curr_power = 1;
    int next_power = 2;
    while(curr_power<n)
    {
        // cout<<curr_power<<" "<<next_power<<endl;
        for(int i = min(n, next_power-1); i>=curr_power; i--)
            answer.push_back(i);
        curr_power*=2;
        next_power*=2;
    }
    for(int i = 0; i<n; i++)
        cout<<answer[i]<<" ";
    cout<<endl;

    int flag=1;
    for(int i = 0; i<n-1 && flag==1; i++)
        if((answer[i]&answer[i+1])<=0)
            flag=0;
    return flag;
}

int main() {
   int N_limit=10;
   for(int i = 1; i<=N_limit; i++)
   {
        int answer = test_case(i);
        if(answer==-1)
            cout<<i<<" "<<"is a 2s power"<<endl;
        else if(answer==0)
            cout<<i<<" "<<"is a wrong answer"<<endl;
   }
}