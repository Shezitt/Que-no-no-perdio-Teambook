const int primes[3] = {127, 229, 229};
const int mod[3] = {MOD, 998244353, (1<<31)-1};
vi pows[3], invs[3];
vi v[3], rv[3]; 
int n, m;
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
            if (j==1)
                invs[i][j] = inv(pows[i][j], mod[i]);
            else 
                invs[i][j] = (invs[i][j-1]*invs[i][1])%mod[i];
        }
    }
}
void build(string &s, vi *v) {
    int n = s.size();
    for (int i = 0; i<2; i++) v[i][0] = s[0];
    for (int j = 0; j<2;j ++) 
    for (int i= 1; i<n; i++) 
        v[j][i] = (v[j][i-1]+(pows[0][i]*s[i])%mod[j])%mod[j];
}
int fh(int i, int j, vi &v, int k) {
    return (((v[j]-(i? v[i-1]: 0)+mod[k])%mod[k])*invs[k][i])%mod[k];
}