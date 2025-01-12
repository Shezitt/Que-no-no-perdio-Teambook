/*
 * simple idea: just do dfs first and then do 
 * dfs reversed (dfs pass data for child node. 
 * Example: maximum path for each node in O(n): 
 * */
void dfs(int i, int p = -1) {
    // pasa: camino maximo hasta i.
    priority_queue<int> pq;
    for (auto &to: grafo[i])
        if (to!=p)
            dfs(to, i), pq.push(dp[to]);
    if (pq.size()) {
        dp[i] = pq.top()+1; pq.pop();
        if (pq.size()) maxi[i] = pq.top()+1;
    }
}
void dfss(int i, int p  = -1, int k = 0) {
    priority_queue<int> pq;
    pq.push(dp[i]); pq.push(maxi[i]), pq.push(k);
    dp[i] = pq.top(); pq.pop();
    maxi[i] = pq.top(); pq.pop();
    for (auto &to: grafo[i])
        if (to!=p) {
            int r = dp[i]==dp[to]+1? maxi[i]: dp[i];
            dfss(to, i, r+1);
        }
}
