vi v(N+1, INF);
void update(int i, int x, int n) {
	i+=k; 
	for (v[i] = x; i; i>>=1) v[i>>1] = min(v[i], v[i^1]); 
}
int query(int i, int j, int n) {
	int res = INF;
	for (i+=k, j+=k; i<j; i>>=1, j>>=1) {
		if (i&1) res = min(res, v[i++]); 
		if (j&1) res = min(res, v[--j]);
	}
	return res;
}
void build(int p, int n) {
	fori(i, 0, n) cin>>v[i+k];
	forir(i, k-1, 0) v[i] = min(v[i<<1], v[i<<1|1]);
}