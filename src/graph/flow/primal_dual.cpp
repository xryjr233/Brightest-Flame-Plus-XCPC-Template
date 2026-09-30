namespace MCMF
{
	using T = int; constexpr T inf = numeric_limits < T >::max() >> 1;
	int n, s, t, fr[N]; bool vis[N]; T h[N], d[N];
	vector < tuple < int, int, T, int > > g[N];
	queue < int > q; priority_queue < pair < T, int > > pq;
	inline void init(int n_, int s_, int t_) { n = n_, s = s_, t = t_; For(i, 1, n) g[i].clear(); }
	inline void init(int n_) { init(n_ + 2, n_ + 1, n_ + 2); }
	inline void ae(int u, int v, int w, T c)
	{
		g[u].emplace_back(v, w, c, (int)g[v].size()),
		g[v].emplace_back(u, 0, -c, (int)g[u].size() - 1);
	}
	inline void spfa()
	{
		fill(h + 1, h + n + 1, inf), h[s] = 0, fill(vis + 1, vis + n + 1, false), q.push(s);
		for ( int u ; q.size() ; )
		{
			u = q.front(), q.pop(), vis[u] = false;
			for ( auto [v, w, c, id] : g[u] ) if ( w && h[v] > h[u] + c )
			{
				h[v] = h[u] + c;
				if ( !vis[v] ) vis[v] = true, q.push(v);
			}
		}
	}
	inline bool dij()
	{
		fill(d + 1, d + n + 1, inf), d[s] = 0, fill(vis + 1, vis + n + 1, false), pq.emplace(0, s);
		for ( int u ; pq.size() ; )
		{
			u = pq.top().second, pq.pop();
			if ( vis[u] ) continue; vis[u] = true;
			for ( auto [v, w, c, id] : g[u] ) if ( w && d[v] > d[u] + c + h[u] - h[v] )
				d[v] = d[u] + c + h[u] - h[v], fr[v] = id, pq.emplace(-d[v], v);
		}
		return d[t] < inf;
	}
	inline pair < int, T > mcmf()
	{
		int flow = 0, cur; T cost = 0;
		for ( spfa() ; dij() ; )
		{
			cur = inf; For(i, 1, n) h[i] += d[i];
			for ( int u = t ; u != s ; )
			{
				auto [v, w, c, id] = g[u][fr[u]];
				cur = min(cur, get<1>(g[v][id])), u = v;
			}
			flow += cur, cost += cur * h[t];
			for ( int u = t ; u != s ; )
			{
				auto &[v, w, c, id] = g[u][fr[u]];
				get<1>(g[v][id]) -= cur, w += cur, u = v;
			}
		}
		return pair(flow, cost);
	}
}