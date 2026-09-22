setpoly convinv(const setpoly &x, const setpoly &z) {
	assert(x[0]);
	int m = x.size(), n = __lg(m);
	setpoly a((n + 1) << n), b((n + 1) << n), y(m);
	int t = qpow(x[0], P - 2);
	for (int i = 0; i != m; i++) {
		int j = i * (n + 1) + __builtin_popcount(i);
		a[j] = (ll)x[i] * t % P, b[j] = (ll)z[i] * t % P;
	}
	for (int i = 0, s = 0; i != m; i++) {
		for (int j = i ? __builtin_ctz(i) : n; j--; ) {
			int o = (n + 1) << j;
			for (int k = s; k != s + o; k++) {
				(a[k + o] += a[k]) >= P && (a[k + o] -= P);
				(b[k + o] += b[k]) >= P && (b[k + o] -= P);
			}
		}
		int c = __builtin_popcount(i);
		for (int j = 0; j <= n; j++) {
			int v = P - b[s + j];
			for (int k = s + 1; k <= s + min(c, n - j); k++)
				b[k + j] = (b[k + j] + (ll)a[k] * v) % P;
		}
		s += n + 1;
		int d = __builtin_ctz(i + 1);
		for (int j = 0; j != d; j++) {
			int o = (n + 1) << j;
			for (int k = s - o; k != s; k++)
				(b[k] -= b[k - o]) < 0 && (b[k] += P);
		}
	}
	for (int i = 0; i != m; i++)
		y[i] = b[i * (n + 1) + __builtin_popcount(i)];
	return y;
}
setpoly inv(const setpoly &x) {
	setpoly z(x.size());
	return z[0] = 1, convinv(x, z);
}