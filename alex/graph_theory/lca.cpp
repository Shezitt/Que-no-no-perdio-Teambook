int n, q;
vi grafo[N+1], tin(N+1, 0), tout(N+1, 0);
vector<vi> dp(N+1, vi(32, -1));
int timer = 0, l;
void dfs(int i, int p) {
	tin[i] = timer++;
	dp[i][0] = p;
	for (int j = 1; j<=l; j++) 
		dp[i][j] = dp[dp[i][j-1]][j-1];
	
	for (auto x: grafo[i])
	dfs(x, i);
	tout[i] = timer++;
}
int low_bit(int x) {return x&(-x);}
int is_ancestor(int i, int j) {
	return tin[i]<tin[j] && tout[i]>tout[j];
}
int lca(int i, int j) {
	if (is_ancestor(i, j)) return i;
	if (is_ancestor(j, i)) return j;
	for (int k = l; k>-1; k--) 
		if (!is_ancestor(dp[i][k], j)) i = dp[i][k];
	return dp[i][0];
}
void solve() {
	cin>>n>>q;
	l = ceil(log2(n))+1;
	for (int i = 2; i<n+1; i++) {
		int x; cin>>x;
		grafo[x].pb(i);
	}
	dfs(1, 1);
	
	while (q--) {
		int x, y; cin>>x>>y;
		if (x==y) {
			cout<<x<<endl;
			continue;
		}
		cout<<lca(x, y)<<endl;
	}
}