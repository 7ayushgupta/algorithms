#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;

int solve_k_1(int n, int k)
{
    vector<int> v(n), families_hash(101, 0);
    int maximum_val = 0;
    map<int, int> families_map;
    for (int i = 0; i<n; i++)
    {
        cin >> v[i];
        families_hash[v[i]]++;
    }
    if(k >= n)
    {
        int a = 0;
        for(int i = 0; i<101; i++)
        {
            if(families_hash[i] > 1) 
            a+= families_hash[i];
        }
        return k+a;
    }
    for(int i = 0; i<101; i++)
        maximum_val = max(maximum_val, families_hash[i]);

    ll cost = 0, result = 0;
    for(int i = 1; i<maximum_val+2; i++)
    {
        families_map.clear();
        cost = 0;
        result = 0;
        for(int j = 0; j<n; j++)
        {
            if(families_map.find(v[j]) == families_map.end())
                families_map[v[j]]++;
            else if(families_map[v[j]] < i)
            {
                if(families_map[v[j]] == 1) 
                    result += 2;
                else 
                    result++;
                families_map[v[j]]++;
            }
            else
            {
                cost += k + result;
                result = 0;
                families_map.clear();
                families_map[v[j]]++;
            }
        }
        if(families_map.size() > 0)
            cost += k + result;
        
        return cost;
    }
}

int solve(vector<int> v, int l, int r)
{
    if(l == r)
        return k;
    map<int, int> state;
    vector<int> calculate(r - l + 1);
    int result = 0, cost = 0;
    for(int i = l; i < r+1; i++)
    {
        if(state.find(v[i]) != state.end())
        {
            if(state[v[i]] == 1) 
                result += 2;
            else
                result++;
        }
        state[v[i]]++;
        calculate[i - l] = result;
    }
    int maximum_val = k + result;
    int ind = l;
    for(int i = 0; i<r-l; i++)
    {
        cost = 2 * k + calculate[i];
        if(state[v[i + l]] == 2) 
            result -= 2;
        else if(state[v[i + l]] > 1) 
            result--;
        state[v[i + l]]--;
        cost += result;
        if(maximum_val >= cost)
        {
            maximum_val = cost;
            ind = i;
        }
    }
    if(ind == l)
        return maximum_val;
    return min(maximum_val, solve(v, l, l + ind) + solve(v, l + ind + 1, r));
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        if(k == 1)
            cout<<solve_k_1(n, k)<<endl;
        else
        {
            vector<int> v(n);
            for(int i= 0; i<n; i++)
                cin>>v[i];
            cout<<solve(v, 0, n - 1)<<endl;
        }
    }
    return 0;
} 