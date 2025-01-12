#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	vector<int> mapa(int(1e6), 0);
	int res= 1, n;
	cin>>n; 
	for (int s = 0; s<n; s++) {
		int x; cin>>x;
		for (int i = 1; i*i<=x; i++) 
		if (!(x%i)) {
			mapa[i]++;
			if (mapa[i]>1) res = max(res, i);
			if (i*i!=x) {
				mapa[x/i]++;
				if (mapa[x/i]>1) 
					res = max(res, x/i);
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}
