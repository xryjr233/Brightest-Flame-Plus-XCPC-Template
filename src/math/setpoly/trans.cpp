setpoly trans(setpoly f, int c, int *graph) {
	int m = f.size(), n = __lg(m);
	setpoly id(m >> 1), g(m >> 1), h(m >> 1);
	for (int i = 0; i < n; i++) {
		int msk = graph[i] & ((1 << i) - 1);
		for (int j = 0; j < (m >> 1); j++) {
			id[j] = 0;
			for (int k = 0; k < n - 1; k++)
				if (j & (1 << k))
					id[j] |= 1 << (k + (k >= i));
			g[j] = f[id[j] | (1 << i)];
			h[j] = (ll)f[id[j]] * c % P
					* __builtin_popcount(j & msk) % P;
		}
		g = conv(g, exp(h));
		for (int j = 0; j < (m >> 1); j++)
			f[id[j] | (1 << i)] = g[j];
	}
	return f;
}
// example: 边双连通生成子图计数
int n, m, graph[18];
int main() {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v, u--, v--;
		graph[u] |= 1 << v, graph[v] |= 1 << u;
	}
	setpoly f(1 << n);
	for (int S = 0; S < (1 << n); S++) {
		int cnt = 0;
		for (int u = 0; u < n; u++)
			if (S & (1 << u))
				cnt += __builtin_popcount(graph[u] & S);
		f[S] = qpow(2, cnt >> 1);
	}
	f = ln(f);
	f = trans(f, P - 1, graph);
	cout << f.back() << '\n';
}