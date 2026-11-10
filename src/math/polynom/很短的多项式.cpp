constexpr int P = 998244353, G = 3;
int add(int x, int y) {
	x += y;
	return x < P ? x : x - P;
}
int sub(int x, int y) {
	x -= y;
	return x >= 0 ? x : x + P;
}
int qpow(int x, int e) {
	int res = 1;
	for (; e; e >>= 1) {
		if (e & 1) res = (ll)res * x % P;
		x = (ll)x * x % P;
	}
	return res;
}
using poly = vector<int>;

void dft(poly &a) {
	static poly r, rt = {0, 1};
	int n = a.size();
	assert(__builtin_popcount(n) == 1);
	if (r.size() != n) {
		r.resize(n);
		for (int i = 0; i < n; i++)
			r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
	}
	for (int i = 0; i < n; i++) {
		if (r[i] < i) swap(a[i], a[r[i]]);
	}
	if (rt.size() < n) {
		int i = __lg(rt.size());
		for (rt.resize(n); (1 << i) < n; i++) {
			int w = qpow(G, (P - 1) >> (i + 1));
			for (int j = 1 << (i - 1); j < (1 << i); j++)
				rt[j << 1] = rt[j], rt[j << 1 | 1] = (ll)rt[j] * w % P;
		}
	}
	for (int k = 1; k < n; k <<= 1) {
		for (int i = 0; i < n; i += k << 1) {
			for (int j = 0; j < k; j++)
			{
				int u = a[i + j], v = (ll)a[i + j + k] * rt[j + k] % P;
				a[i + j] = add(u, v), a[i + j + k] = sub(u, v);
			}
		}
	}
}
void idft(poly &a) {
	int n = a.size(), w = qpow(n, P - 2);
	reverse(a.begin() + 1, a.end()), dft(a);
	for (int &x : a) x = (ll)x * w % P;
}
poly operator*(poly x, poly y) {
	if (x.empty() || y.empty()) return {};
	// 可以加常数优化: size 较小时暴力卷积
	int n = x.size() + y.size() - 1, m = n < 3 ? n : 2 << __lg(n - 1);
	x.resize(m), y.resize(m), dft(x), dft(y);
	for (int i = 0; i < m; i++) x[i] = (ll)x[i] * y[i] % P;
	idft(x), x.resize(n);
	return x;
}

poly divxk(const poly &a, int k) {
	if (k >= a.size()) return {};
	return poly(a.begin() + k, a.end());
}
poly modxk(const poly &a, int k) {
	if (k >= a.size()) return a;
	return poly(a.begin(), a.begin() + k);
}
poly operator+(poly a, const poly &b) {
	if (a.size() < b.size()) a.resize(b.size());
	for (int i = 0; i < b.size(); i++) a[i] = add(a[i], b[i]);
	return a;
}
poly operator-(poly a, const poly &b) {
	if (a.size() < b.size()) a.resize(b.size());
	for (int i = 0; i < b.size(); i++) a[i] = sub(a[i], b[i]);
	return a;
}
poly operator*(poly a, int b) {
	for (int &x : a) x = (ll)x * b % P;
	return a;
}

poly inv(const poly &a, int m) {
	assert(a[0]);
	int n = 1;
	poly b = {qpow(a[0], P - 2)};
	while (n < m) n <<= 1, b = modxk((poly({2}) - modxk(a, n) * b) * b, n);
	return modxk(b, m);
}

poly deriv(const poly &a) {
	if (a.empty()) return {};
	poly b(a.size() - 1);
	for (int i = 1; i < a.size(); i++) b[i - 1] = (ll)a[i] * i % P;
	return b;
}
poly integ(const poly &a) {
	poly b(a.size() + 1);
	for (int i = 1; i <= a.size(); i++) b[i] = (ll)a[i - 1] * qpow(i, P - 2) % P;
	return b;
}
poly ln(const poly &a, int m) {
	assert(a[0] == 1);
	return modxk(integ(deriv(a) * inv(a, m)), m);
}
poly exp(const poly &a, int m) {
	assert(!a[0]);
	int n = 1;
	poly b = {1};
	while (n < m) n <<= 1, b = modxk((modxk(a, n) + poly({1}) - ln(b, n)) * b, n);
	return modxk(b, m);
}
poly sqrt(const poly &a, int m) {
	assert(a[0] == 1); // 二次剩余?
	int n = 1;
	poly b = {1};
	while (n < m) n <<= 1, b = (modxk(modxk(a, n) * inv(b, n), n) + b) * ((P + 1) / 2);
	return modxk(b, m);
}

poly mulT(const poly &a, poly b) {
	if (b.empty()) return {};
	reverse(b.begin(), b.end());
	return divxk(a * b, b.size() - 1);
}
poly eval(const poly &a, const poly &x) { // 多点求值
	int m = x.size();
	poly y(m);
	if (a.empty()) return y;
	int n = max(a.size(), x.size());
	vector<poly> t(n << 2);
	auto build = [&](auto &&self, int p, int l, int r) -> void {
		if (l == r) {
			t[p] = {1, l < m ? sub(0, x[l]) : 0};
		} else {
			int md = (l + r) >> 1;
			self(self, p << 1, l, md), self(self, p << 1 | 1, md + 1, r);
			t[p] = t[p << 1] * t[p << 1 | 1];
		}
	};
	build(build, 1, 0, n - 1);
	auto solve = [&](auto &&self, int p, int l, int r, const poly &f) -> void {
		if (l == r) {
			if (l < m) y[l] = f[0];
		} else {
			int md = (l + r) >> 1;
			self(self, p << 1, l, md, modxk(mulT(f, t[p << 1 | 1]), md - l + 1));
			self(self, p << 1 | 1, md + 1, r, modxk(mulT(f, t[p << 1]), r - md));
		}
	};
	solve(solve, 1, 0, n - 1, mulT(a, inv(t[1], n)));
	return y;
}