signed main() {
	/*
	 * ternary for integer search
	 * */
	int l = 0, h = n; 
	while (l<=h) {
		int diff = (h-l)/3;
		int m1 = l+diff, m2 = f-diff;
		if (f(m1)>f(m2)) f = m2-1;
		else l = m1+1;
	}
	return 0;
}
