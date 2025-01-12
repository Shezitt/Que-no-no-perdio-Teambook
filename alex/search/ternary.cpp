signed main() {
	double l = 0, f = 1e9; 
	while (f-l>1e-8) {
		double mid1 = l+(f-l)/3; 
		double mid2 = f-(f-l)/3; 
		if (ff(mid1)>ff(mid2)) l = mid1; 
		else f = mid2;
	}
	return 0;
}
