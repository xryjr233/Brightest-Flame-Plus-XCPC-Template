__int128 Solve(ll a,ll b,ll c,ll n){
	ll ta=(a%c+c)%c,tb=(b%c+c)%c;
	__int128 res=(__int128((a-ta)/c)*n*(n+1)>>1)+((b-tb)/c)*(n+1);
	if(!ta)return res;
	ll m=(ta*n+tb)/c;
	res+=__int128(n)*m;
	return res-Solve(c,c-tb-1,ta,m-1);
}