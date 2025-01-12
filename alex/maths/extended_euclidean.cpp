int gcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int xs, ys; 
	int g = gcd(b, b%a, xs, ys);
	x = ys, y = xs-ys*(a/b);
	return g;
}
int main() {
	int n, a, b; cin>>n>>a>>b;
	int x, y; 
	int g = gcd(a, b, x, y);
	x *= n/g, y*=n/g;
	for (int i = -3; i<4; i++) {
		int xs = x+i*(b/g), ys = y-i*(a/g);
		cout<<xs<<' '<<ys<<'\n'; // possible solutions
	}
}
