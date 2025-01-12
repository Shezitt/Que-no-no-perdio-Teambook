struct matrix {
	int matr[2][2];
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c; 
		for (int i= 0 ; i<2; i++) 
		for (int j = 0; j<2; j++) {
			c.matr[i][j] = 0;
			for (int k =0 ; k<2; k++) 
				c.matr[i][j]+=a.matr[i][k]*b.matr[k][j];
		}
		return c;
	}
};
matrix binpow(matrix a, int n) {
	matrix res{{
		{1, 0},
		{0, 1}
	}};
	while (n) {
		if (n&1) res = res*a;
		a = a*a;
		n>>=1;
	}
	return res;
}
int fast_algorithm(int n) {
	matrix base{{
		{1, 1},
		{1, 0}
	}};
	return binpow(base, n).matr[0][1];
}
int naive_algorithm(int n) {
	int a = 0, b = 1;
	for (int i=0 ; i<n; i++) {
		int aux = a+b;
		a = b;
		b = aux;
	}
	return a;
}