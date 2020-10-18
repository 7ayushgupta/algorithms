int Solution::minDistance(string A, string B) {
	int m = A.length();
	int n = B.length();

	int dp[m+1][n+1];
	
	for (int i = 0; i<=m; i++)
		dp[i][0]=i;
	for (int i = 0; i<=n; i++)
		dp[0][i]=i;

	for (int i = 1; i<=m; i++)
		for(int j = 1; j<=n; j++)
		{
		    int dist;
		    if(A[i-1]==B[j-1])
		        dist=0;
		    else
		        dist=1;
		        
			dp[i][j]=min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + dist);
		}
		
	return dp[m][n];
}