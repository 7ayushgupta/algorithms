vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    stack<int> s;
    vector<int> max_upto(n);
    s.push(0);
    for(int i = 1; i<A.size(); i++)
    {
        //for minima just turn the sign down
        while(!s.empty() && A[s.top()] < A[i])
        {
            max_upto[s.top()] = i-1;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        max_upto[s.top()]=n-1;
        s.pop();
    }
    int j = 0;
    vector<int> answer;
    for(int i = 0; i<=n-B; i++)
    {
        while(j<i || max_upto[j] < i+B-1)
            j++;
        answer.push_back(A[j]);
    }
    return answer;
}
