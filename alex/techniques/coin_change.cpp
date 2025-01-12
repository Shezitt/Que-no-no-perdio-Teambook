#include <bits/stdc++.h>
using namespace std; 
signed main() {
	// coin change optimization over n -> 1e9 xor max_value_coin<1e4
	int n, piv; cin>>n; 
	vi coins, dp;
	// you have m distinct coins: 
	sort(coins.begin(), coins.end()); 
	piv = lcm(coins[m-1], coins[max(0ll, m-2)]); // upper_bound +10 
	dp.resize(m+100, INF);
	dp[0] =0 ;
	for (int i= 1 ;i<m; i++) 
	for (auto x: coins) 
		if (i-x>-1) dp[i] = min(dp[i], dp[i-x]+1);

	int res = INF;
	if (n<m) res= dp[n];
	else {
		for (int i = 0; i<m; i++) {
			int r = n-i; 
			if (r%coins[m-1]==0) res = min(res, dp[i]+r/coins[m-1]);
		}
	}
	return res;
	
}
