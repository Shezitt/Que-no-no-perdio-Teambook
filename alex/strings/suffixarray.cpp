vi sa, ra, lcp, t;
int n;
void buildsa(string &s) {
    int n= s.size();
    vi p(n), c(n); 
    vector<pair<pair<int,int>,int>> a(n); 
    for (int i=0; i<n; i++) a[i] = {{s[i], 0}, i}; 
    sort(a.begin(), a.end()); 
    for (int i=0; i<n; i++) p[i] = a[i].S;
    c[p[0]] = 0; 
    for (int i = 1; i<n; i++) c[p[i]] = c[p[i-1]]+(a[i].F==a[i-1].F? 0: 1);
    for (int k = 0; (1ll<<k)<n; k++) {
        for (int i =0 ; i<n; i++) a[i] = {{c[i], c[(i+(1<<k))%n]}, i}; 
        sort(a.begin(), a.end()); 
        for (int i=0 ; i<n; i++) p[i] = a[i].S; 
        c[p[0]] = 0; 
        for (int i =1; i<n; i++) c[p[i]] = c[p[i-1]]+(a[i].F==a[i-1].F? 0:1);
    }
    sa = p;
}
void buildLCP() {
	vi phi(n), plcp(n); 
	phi[sa[0]] = -1;
	for (int i= 1; i<n; i++) phi[sa[i]] = sa[i-1];
	for (int i= 0, L = 0; i<n; i++) {
		if (phi[i]==-1) {plcp[i] = 0; continue;}
		while ((i+L<n) && phi[i]+L<n && t[i+L]==t[phi[i]+L]) L++;
		plcp[i] = L;
		L = max(L-1, 0ll);
	}
	lcp.resize(n); 
	for (int i= 0; i<n; i++) lcp[i] = plcp[sa[i]];
}