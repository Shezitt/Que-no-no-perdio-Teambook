vl v(N+1, 0), rak(N+1, 1);
vl graph[N+1];
set<ll, cor> edges;
ll find(ll x) {
	return x==v[x]? x: v[x] = find(v[x]);
}
void merge(ll x, ll y) {
	x = find(x), y = find(y);
	if (x==y) return ;
	if (rak[x]<rak[y]) swap(x, y);
	rak[x]+=rak[y];
	v[y] = x;
}
ll same(ll x, ll y) {
	x = find(x), y = find(y);
	return x==y;
}
int main() {
	// build the graph and insert the edges
	// the build the new minimum graph weighted
	// time complexity: O(E log E)
	return 0;
}
