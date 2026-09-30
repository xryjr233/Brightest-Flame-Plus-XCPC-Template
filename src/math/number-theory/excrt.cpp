ll exCRT(ll r1,ll m1,ll r2,ll m2){
	ll a1,a2,g=std::gcd(m1,m2);
	if((r1-r2)%g)return -1;
	exgcd(m1,m2,a1,a2);
	ll k=__int128((r2-r1)%m2+m2)*(a1+m2)%m2;
	return m1/g*k+r1;
}