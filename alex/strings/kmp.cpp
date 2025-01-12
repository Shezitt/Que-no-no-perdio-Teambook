vi kmpp(string &s, int n) {
    vi dp(n, 0);
    int j= 0; 
    for (int i = 1; i<n; i++) {
        while (j && s[i]!=s[j]) j = dp[j-1]; 
        if (s[i]==s[j]) dp[i] = ++j; 
        else dp[i] = 0;
    }
    return dp; 
}
vi kmp(string &t, string &p) {
    string q = p+"#"+t; 
    vi v = kmpp(q, q.size()); 
    vi res;
    for (int i=0 ; i<q.size(); i++) 
    if (v[i]==p.size()) {
        res.push_back(i-2*p.size()+1);
    }
    return res;
}