int __lcm(int x,int y) { return (x*y)/__gcd(x, y);}
int n,m;
int binpow(int base, int exp) {
	int res = 1; 
	for (; exp; exp>>=1, base = (base*base)%MOD)
	if (exp&1) res = (res*base)%MOD;
	return res;
}