vi grafo[N+1], v(N+1, 0), dis(N+1, INF);
signed main() {
    // realiza el grafo
    // para grafo con multiples destinos
    // si es para un unico origen solo aumentar: dis[i]!=INF antes de visitar las aristas del nodo.
	for (int k = 0; k<n; k++) {
        int modif = 0;
        for (int i = 1; i<=n; i++) 
        for (auto it: grafo[i]) {
            int to = it.F, len = it.S; 
            if (dis[to]>dis[i]+len) {
                v[to] = i;
                dis[to]  = dis[i]+len;
                modif = 1;
            }
        }
        if (!modif) break;
    }
    int ncycle = 0;
    for (int i = 1; i<=n; i++) 
        for (auto it: grafo[i]) {
            int to = it.F, len = it.S; 
            if (dis[to]>dis[i]+len) {
                ncycle = i;
            }
        }

    if (!ncycle) {
        // there is no negative cycle
    } else {
        // negative cycle 
    }
}
