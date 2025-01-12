vi grafo[N], inc(N, 0), topo;
int n, m, y; 
void kanh() {
    // vs topological
    priority_queue<int,vi,greater<int>> pq;
    for (int i= 1; i<=n; i++) 
    if (!inc[i]) pq.push(i);
    y = 0;
    while (pq.size()) {
        int i = pq.top();
        topo.pb(i);
        pq.pop();
        for (auto x: grafo[i])
        if (!(--inc[x])) pq.push(x);
        y++;
    }
}