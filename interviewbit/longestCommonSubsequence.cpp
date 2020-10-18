int Solution::solve(string A, string B) {
    int row=A.length();
    int col=B.length();
    
    int dp[row+1][col+1];
    for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            if(i==0 || j==0){ // if first row or col, consider it LCS with empty string and so val=0
                dp[i][j]=0;
            }
            else if(A[i-1]==B[j-1]){ // Build bottom to up matrix, because we are considering an added empty string befor the actual string so A[0] becomes A[1]
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=std::max(dp[i-1][j], dp[i][j-1]); // if elements are not equal take max of row and col
            }
        }
    }
    return dp[row][col]; // return last element in matrix as result
}