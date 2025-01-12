int block;
struct query {
    int l, r, i; 
    bool operator< (const query &o) {
        if (o.l/block == l/block) 
        return (l/block)&1? o.r < r: r < o.r;
        return l <= o.l; 
    } 
};
struct ans{
    int L, R, ac;
    vi res, v, dp;
    ans(vi &a, int q): L(0), R(0){
        v = a;
        res.resize(q, 0);
        ac = 1;
        dp.resize(N, 0);
        dp[v[0]] = 1;
    }
    void add(int ok = 0) { // 0 is for left
        (ok? R++: L--);
        int i = ok? R: L;
        if ((++dp[v[i]])==1) ac++;
    }
    void erase(int ok = 0) {
        int i = ok? R: L;
        if (!(--dp[v[i]])) ac--;
        (ok? R--: L++);
    }
    void query(int i) {res[i] = ac;}
};
vi mo(vi &v, vector<query> &a) {
    ans r(v, a.size());
    sort(a.begin(), a.end());
    for (auto &q: a) {
        q.l--, q.r--;
        while (r.L > q.l ) r.add();
        while (r.R < q.r ) r.add(1); 
        while (r.L < q.l ) r.erase();
        while (r.R > q.r ) r.erase(1);
        r.query(q.i);
    }
    return r.res;
}\