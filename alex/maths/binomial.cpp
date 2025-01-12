vi fac(N, 1), infa(N, 1);
int pow(int b, int e) {
    int res = 1; 
    for (; e; e>>=1, b = (b*b)%mod)
        if (e&1) res = res*b%mod;
    return res;
}
void init() {
    for (int i = 2; i<N;i ++) {
        fac[i] = fac[i-1]*i%mod;
        infa[i] = pow(fac[i], mod-2);
    }
}
int C(int n, int k) {
    assert(k>=0);
    if (k>n) return 0;
    return fac[n]*infa[k]%mod*infa[n-k]%mod;
}