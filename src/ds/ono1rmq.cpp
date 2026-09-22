// less<T>: min   greater<T>: max
template<class T, int N, class CMP = less<T>>
class RMQ {
	const static CMP cmp;
	static T calc(const T &x, const T &y) { return cmp(x, y) ? x : y; }
	T val[N], pre[N], st[__lg((N >> 5) + 1) + 1][(N >> 5) + 9];
	unsigned f[N];
public:
	void build(int n, T *a) { // 1-index
		int m = (n - 1) >> 5, o = __lg(m + 1), stk[33];
		copy(a + 1, a + n + 1, val);
		for (int i = 0; i < n; i++)
			pre[i] = i & 31 ? calc(pre[i - 1], val[i]) : val[i];
		for (int i = 0; i <= m; i++)
			st[0][i] = pre[min(n - 1, i << 5 | 31)];
		for (int i = 1; i <= o; i++)
			for (int j = 0; j <= m + 1 - (1 << i); j++)
				st[i][j] = calc(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		for (int i = 0; i < n; i++)
			if (i & 31) {
				f[i] = f[i - 1];
				while (o && !cmp(val[stk[o]], val[i]))
					f[i] ^= 1u << (stk[o--] & 31);
				stk[++o] = i, f[i] |= 1u << (i & 31);
			} else stk[o = 1] = i, f[i] = 1u << (i & 31);
	}
	T qry(int l, int r) { // assume 1<=l<=r<=n
		if ((--l >> 5) == (--r >> 5))
			return val[l + __builtin_ctz(f[r] >> (l & 31))];
		T res = calc(pre[r], val[l + __builtin_ctz(f[l | 31] >> (l & 31))]);
		l = (l >> 5) + 1, r >>= 5;
		if (l == r) return res;
		int t = __lg(r - l);
		return calc(res, calc(st[t][l], st[t][r - (1 << t)]));
	}
};