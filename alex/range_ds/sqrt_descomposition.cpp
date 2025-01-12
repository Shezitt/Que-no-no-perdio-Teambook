vi v, p;
int block, n, q;
int query(int i) {
    if (i<0) return 0;
    int res = 0;
    for (int j = 0; j<i/block; j++) res+=p[j];
    for (int j = (i/block)*block; j<=i; j++) res+=v[j]; 
    return res;
}
void sqrt_() {
    block = sqrt(n)+2;
    v.resize(n, 0), p.resize(block, 0); 
    for (int i =0 ; i<n;i++) p[i/block]+=v[i];
    for (; q--; ) {
        if (query) {
            int l, r; cin>>l>>r; l--, r--;
            cout<<query(r)-query(l-1)<<endl; // sum in range
        } else {// point update
            int i, x; cin>>i>>x; i--;
            p[i/block]-=v[i];
            v[i] = x;
            p[i/block]+=v[i];
        }
    }
}
