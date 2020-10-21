class Solution {
public:
    bool canCross(vector<int>& stones)
    {
        const int m = stones.size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(m + 1));
       
        if(stones[1] == 1){
            dp[1][1] = true; // with a jump of step size 1, the frog reaches the 1st position.
        }
        
        for(int i = 1; i < stones.size(); ++i){
            for(int j = i + 1; j < stones.size(); ++j){
                if(const int diff = stones[j] - stones[i]; diff <= j){
                    dp[j][diff] = dp[i][diff-1] || dp[i][diff] || dp[i][diff+1];
                }
            }
        }
        return std::accumulate(dp[m-1].begin(), dp[m-1].end(), 0) > 0;
    }
};