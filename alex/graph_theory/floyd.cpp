signed main() {
    int n; 
    vector<vi> dp(n, vi(n, INF));
    // dp[i][i] = 0, for all i-> 0..n-1
    for (int k = 0; k<n; k++) 
    for (int i = 0; i<n; i++) 
    for (int j = 0;j <n; j++) 
        if (max(dp[i][k], dp[k][j])<INF)
            dp[i][j] = min(min(dp[i][j], dp[j][i]), dp[i][k]+dp[k][j]);

    return 0;
}