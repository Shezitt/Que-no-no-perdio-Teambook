vector<pair<int,int>> grafo[N+1];
vi dis(N+1, 0);
void f(int i) {
	dis[i] = 0; 
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
	pq.push({0, i}); 
	while (pq.size()) {
		int i = pq.top().S, len = pq.top().F; 
		pq.pop(); 
		if (len > dis[v]) continue;
		for (auto &[to, lto]: grafo[i]) 
		if (dis[to] > len+lto) {
			dis[to] = len+lto; 
			pq.push({-dis[to], to});
			p[to] = i; 
		}
	}
}
vi path(int i, int j) {
	int v = j;
	vi res;
	while (v!=i) res.push_back(v), v = p[v];
	res.push_back(i);
	return res;
}