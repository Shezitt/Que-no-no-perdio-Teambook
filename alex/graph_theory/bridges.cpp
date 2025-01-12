vi grafo[N], tin(N), low(N), vis(N); 
vi<pair<int,int>> s; 
int timer, n, m, x;
void bridge(int i, int j) {
    if (i>j) swap(i, j); 
    s.pb({i, j});
}
int is_bridge(int i,int j) {
    if (i>j) swap(i, j); 
    int k = lower_bound(s.begin(), s.end(), make_pair(i, j))-s.begin();
    return k>=s.size() && s[k]!=make_pair(i, j);
}
void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : grafo[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridge(v, to);
        }
    }
}
void find_bridges() {
    timer = 0;
    for (int i = 1; i <= n; ++i) 
        if (!vis[i]) dfs(i);
}
void init() {
    // multiple paths between 2 nodes: (FAST)
    vector<pair<int,int>> edges(m);
    // cin with i<j to edges
    sort(edges.begin(), edges.end());
    find_bridges();
    stack<pair<int,int>> st; 
    for (; s.size(); s.pop_back()) st.push(s.back()); 
    for (; st.size(); st.pop()) {
        auto aaa = st.top();
        int j = lower_bound(edges.begin(), edges.end(), aaa)-edges.end();
        if (j+1 < edges.size() && edges[j]==edges[j+1]) continue;
        s.pb(aaa);
    }
}