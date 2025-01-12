int n, q;
vi grafo[N+1];
vector<vi> dp(N+1, vi(30, -1));
void dfs(int i, int p) {
	if (i>1) {
		dp[i][0] = p;
		for (int j = 1; j<30 && dp[i][j-1]!=-1; j++) 
			dp[i][j] = dp[dp[i][j-1]][j-1];
	}
	for (auto x: grafo[i])
	dfs(x, i);
}
int low_bit(int x) {return x&(-x);}
void solve() {
	cin>>n>>q;
	for (int i = 2; i<n+1; i++) {
		int x; cin>>x;
		grafo[x].pb(i);
	}
	dfs(1, -1);
	
	while (q--) {
		int x, y; cin>>x>>y;
		while (y&&x!=-1) {
			int z = low_bit(y), k = 1;
			if (z==1) x = dp[x][0];
			else {
				while ((1ll<<k)<z) k++;
				x = dp[x][k];
			}
			y -= low_bit(y);
		}
		cout<<x<<endl;
	}
}