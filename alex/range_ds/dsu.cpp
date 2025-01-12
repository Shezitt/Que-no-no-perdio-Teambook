vi p(N+1), rank(N+1, 1);
void make_set(int x) {
	p[x] = x;
	rank[x] = 1;
}
int find(int x) {
	return x==p[x]? x: p[x] = find(p[x]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a==b) return; 
	if (rank[a]<rank[b])
		swap(a, b);
	p[b] = a;
	rank[a]+=rank[b];
}
