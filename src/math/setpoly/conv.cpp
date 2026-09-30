setpoly conv(const setpoly &x, const setpoly &y) {
	int m = x.size(), n = __lg(m);
	setpoly a((n + 1) << n), b((n + 1) << n), z(m);
	for (int i = 0; i != m; i++) {
		int j = i * (n + 1) + __builtin_popcount(i);
		a[j] = x[i], b[j] = y[i];
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
		for (int j = min(n, c << 1); j >= c; j--) {
			int v = 0;
			for (int k = j - c; k <= c; k++)
				v = (v + (ll)a[s + k] * b[s + j - k]) % P;
			a[s + j] = v;
		}
		s += n + 1;
		int d = __builtin_ctz(i + 1);
		for (int j = 0; j != d; j++) {
			int o = (n + 1) << j;
			for (int k = s - o; k != s; k++)
				(a[k] -= a[k - o]) < 0 && (a[k] += P);
		}
	}
	for (int i = 0; i != m; i++)
		z[i] = a[i * (n + 1) + __builtin_popcount(i)];
	return z;
}