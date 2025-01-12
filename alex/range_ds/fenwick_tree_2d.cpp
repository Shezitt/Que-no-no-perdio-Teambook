int __lcm(int x,int y) { return (x*y)/__gcd(x, y);}
vector<vi> bit(N+1, vi (N+1, 0)); 
int low_bit(int x) {return x&(-x);}
void updatey(int i, int j, int x) {
	while (j<=N) 
		bit[i][j]+=x, j+=low_bit(j);
}
void update(int i, int j, int x) {
	while (i<=N)
		updatey(i, j, x), i+=low_bit(i);
}
int queryy(int i, int j) {
	int sum =0; 
	while (j>0) 
		sum+=bit[i][j], j-=low_bit(j); 
	return sum;
}
int query(int i, int j) {
	int sum= 0 ; 
	while (i>0) 
		sum+=queryy(i, j), i-=low_bit(i);
	return sum;
}
void solve() {
	int a, b, c, d;
	cin>>a>>b>>c>>d; 
	int sum = query(c, d); 
	sum+=query(a-1,b-1); 
	sum-=query(c, b-1); 
	sum-=query(a-1, d);	
}