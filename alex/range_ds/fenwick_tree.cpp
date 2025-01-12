vi bit(N+1, 0);
int lb(int x) {return x&(-x);}
int query(int i) {
	int sum= 0;
	for (; i; i-=lb(i)) sum+=bit[i];
	return sum;
}
void update(int i, int x) {
	for (; i<N; i+=lb(i)) bit[i]+=x;
}
int lowerbound(int x) {
	int sum =0 , j = 0; 
	fori(i, int(log(n)/log(2)), -1)
		if (j+(1<<i)<n && sum+v[j+(1<<i)]<x)
			sum+=v[j+(1<<i)], j+=(1<<i);
	return j;
}