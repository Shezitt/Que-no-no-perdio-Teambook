const int primes[2] = {31, 37};
const int mod[2] = {MOD, 998244353};
vi pows[2], invs[2];
vi v[2], rv[2]; 
string s;
int n;
int binpow(int b, int e, int m) {
    int res = 1; 
    for(; e; e>>=1, b = (b*b)%m)
    if (e&1) res = (res*b)%m;
    return res;
}
int inv(int b, int m) {
    return binpow(b, m-2,m);
}
void init() {
    for (int i=0; i<2; i++) {
        v[i].resize(N, 0), rv[i].resize(N, 0);
        pows[i].resize(N, 1), invs[i].resize(N, 1);
        for (int j= 1; j<N;j ++) {
            pows[i][j] = (pows[i][j-1]*primes[i])%mod[i];
                invs[i][j] = inv(pows[i][j], mod[i]);
        }
    }
}
void build(vi &v, vi &o) {
    v[0] = s[0];
    o[0] = s[0];
    for (int i= 1; i<n; i++) 
    v[i] = (v[i-1]+(pows[0][i]*s[i])%mod[0])%mod[0];
    for (int i= 1; i<n; i++) 
    o[i] = (o[i-1]+(pows[1][i]*s[i])%mod[1])%mod[1];
}
int fh(int i, int j, vi &v, int k) {
    return (((v[j]-(i? v[i-1]: 0)+mod[k])%mod[k])*invs[k][i])%mod[k];
}
int find(int k) {
    int a = fh(n-k-1, n-1, rv[0], 0), b = fh(n-k-1, n-1, rv[1], 1);
    for (int i= 0; i+k<n; i++) {
        int va = fh(i, i+k, v[0], 0)%mod[0], vb = fh(i, i+k, v[1], 1);
        if (va==a) return 1;
    }
    return 0;
}