vector<int> grafo[N+1];
vector<int> vis(N+1, 0), resp;
int dfs(int i) {
	if (vis[i]) return vis[i]==2;
	vis[i] = 1;
	for (auto a: grafo[i]) 
		if (!dfs(a)) return 0;
	resp.push_back(i);
	vis[i] = 2;
	return 1;
}