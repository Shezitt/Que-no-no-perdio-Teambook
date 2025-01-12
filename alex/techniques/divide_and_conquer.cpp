vi dp(N+1, 0);
int bin(vi &v, int x) {
	int i = 0, j = v.size(), r = j;
	while (i<=j) {
		int mid = (i+j)>>1; 
		if (v[mid]>=x)
			r = mid, j = mid-1;
		else i = mid+1; 
	}
	return r; 
}
void dc(vcor &v, int i, int j) {
	if(j==i) 
		return;
	int mid = (i+j)>>1;
	dc(v, i, mid);
	dc(v, mid+1, j);
	vi aux;
	fori(k,i,mid+1)
		aux.pb(v[k].y);
	sort(aint(aux));
	fori(k,mid+1,j+1) {
		dp[k] = bin(aux, v[k].y);
	}
}