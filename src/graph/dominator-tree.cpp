namespace DT
{
	int n, u, cnt, dfn[N], pos[N], f[N], fa[N], mn[N];
	int sdm[N], idm[N]; vector < int > g0[N], g1[N], g2[N];
	inline void init(int n_)
	{
		n = n_, cnt = 0;
		For(i, 1, n) dfn[i] = idm[i] = 0, fa[i] = mn[i] = sdm[i] = i, g0[i].clear(), g1[i].clear(), g2[i].clear();
	}
	inline void addedge(int u, int v) { g0[u].push_back(v), g1[v].push_back(u); }
	inline void dfs(int u)
	{
		dfn[u] = ++cnt, pos[cnt] = u;
		for ( int v : g0[u] ) if ( !dfn[v] ) f[v] = u, dfs(v);
	}
	inline int fnd(int x)
	{
		if ( fa[x] == x ) return x;
		int f = fnd(fa[x]);
		if ( dfn[sdm[mn[fa[x]]]] < dfn[sdm[mn[x]]] ) mn[x] = mn[fa[x]];
		return fa[x] = f;
	}
	inline void build(int s)
	{
		dfs(s);
		Fol(i, cnt, 2)
		{
			u = pos[i];
			for ( int j : g1[u] ) if ( dfn[j] ) { fnd(j); if ( dfn[sdm[mn[j]]] < dfn[sdm[u]] ) sdm[u] = sdm[mn[j]]; }
			fa[u] = f[u], g2[sdm[u]].push_back(u), u = f[u];
			for ( int j : g2[u] ) fnd(j), idm[j] = u == sdm[mn[j]] ? u : mn[j];
			g2[u].clear();
		}
		For(i, 2, cnt) { u = pos[i]; if ( idm[u] != sdm[u] ) idm[u] = idm[idm[u]]; }
	}
}