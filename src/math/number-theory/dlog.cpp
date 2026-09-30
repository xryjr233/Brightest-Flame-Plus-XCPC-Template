namespace DLOG
{
	constexpr int G = 3; // remember to modify G!!!!!
	unordered_map < int, int > mp;
	int s, p[1 << 15], c; ll f[1 << 15];
	inline int bsgs(int x)
	{
		for ( int i = 0 ; ; i++, x = (ll)x * G % P )
			if ( auto it = mp.find(x) ; it != mp.end() )
				return it -> second - i;
	}
	inline void init()
	{
		int x = qpow(G, 1 << 10), y = 1; mp.clear();
		for ( int i = 0 ; i < P ; mp[y] = i += 1 << 10 )
			y = (ll)y * x % P;
		s = 1 + sqrtl(P), c = 0, fill(f, f + s + 1, 0);
		For(i, 2, s)
		{
			if ( !f[i] ) p[++c] = i, f[i] = bsgs(i); 
			For(j, 1, c)
			{
				if ( i * p[j] > s ) break;
				f[i * p[j]] = f[i] + f[p[j]];
				if ( !( i % p[j] ) ) break;
			}
		}
	}
	inline ll calc(int x)
	{
		if ( x <= s ) return f[x];
		int q = P / x, r = P % x;
		if ( r + r < x ) return calc(r) + P / 2 - f[q];
		else return calc(x - r) - f[q + 1];
	}
	inline int dlog(int x)
	{
		int y = calc(x) % ( P - 1 );
		return y >= 0 ? y : y + P - 1;
	}
}