vi grafo[N+1], vis(N+1, 0), low(N+1,-1), tin(N+1, -1);
int timer;
int n, m;
void dfs(int i, int p = -1) {
	int c = 0;	
	vis[i] = 1;
	tin[i] = low[i] = timer++;
	for (auto x: grafo[i]) {
		if (x==p) continue;
		if (vis[x]) low[i] = min(low[i], tin[x]);
		else {
			dfs(x, i);
			low[i] = min(low[i], low[x]);
			if (low[x]>=tin[i] && p!=-1) 
				PUNTO_ARTICULAR
			c++;
		}
	}
	if (p==-1 && c>1) res.insert(i);
}