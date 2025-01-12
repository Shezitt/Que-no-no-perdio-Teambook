int find(vi &v, int x, int i) {
	int n = v.size();
	//cout<<i<<endl;
	if (i>n || v[i]<x) return -1;
	if (v[i]==x) return i;
	int a = i*2+1, b = i*2+2;
	return max(find(v,x,a),find(v,x,b));
}
void insert(vi &v) {
	int i = v.size()-1; 
	while (i>0) {
		int p = i; 
		if (!(p&1)) p--;
		p>>=1;
	       	if (v[p]>v[i]) break;
		swap(v[p], v[i]); 
		i = p;
	}
} 
void del(vi &v, int i) {
	v[i] = -1;
	int a = i*2+1,b=i*2+2, n=v.size();
	int max = -1;
	if(a<n) max = a;
	if(b<n) 
	       if(v[max]<v[b])
		max = b;
	if(max!=-1)
		swap(v[i], v[max]), del(v,max);
	else {
		swap(v[i],v[n-1]);
		v.pop_back();
	}
}
void solve() {
	int n;
	vi v; cin>>n;
	fori(i,0,n) {
		int x; cin>>x;
		v.pb(x);
		insert(v);
	}
	del(v,3);
	n = v.size();
	fori(i,0,n)
		cout<<v[i]<<" \n"[i==n-1];
	cout<<find(v,2,0)<<endl;
}