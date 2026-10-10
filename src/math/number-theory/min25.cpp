const int mod=1e9+7;
struct Min_25{
	ll n,sn,pn;
	int cnt;
	vector<ll>p;
	vector<int>li,gi;
	vector<ll>vl;
	//f(p)=\sum g_i(p), F_{prime}=G_i=\sum g_i(p_j)
	vector<int>G0,G1,G0p,G1p;
	int g0sum(ll x){
		x%=mod;
		int i6=(mod+1)/6;
		return x*(x+1)%mod*(x<<1|1)%mod*i6%mod;
	}
	int g0(ll x){
		x%=mod;
		return x*x%mod;
	}
	int g1sum(ll x){
		x%=mod;
		int i2=(mod+1)/2;
		return x*(x+1)%mod*i2%mod;
	}
	int g1(ll x){
		return x%mod;
	}
	void getprime(int m){
		p.resize(m);
		G0p.resize(m),G1p.resize(m);
		p[0]=1;
		pn=0;
		for(int i=2;i<=n;++i){
			if(!p[i]){
				p[++pn]=i;
				(G0p[pn]=G0p[pn-1]+g0(i))>=mod?G0p[pn]-=mod:0;
				(G1p[pn]=G1p[pn-1]-g1(i)+mod)>=mod?G1p[pn]-=mod:0;
				if(i>sn)break;
			}
			for(int j=1;j<=pn&&i*p[j]<m;++j){
				p[i*p[j]]=1;
				if(i%p[j]==0)break;
			}
		}
	}
	int idx(ll x){
		return x<=sn?li[x]:gi[n/x];
	}
	void calcprime(){
		G0.resize(cnt+5),G1.resize(cnt+5);
		for(int i=1;i<=cnt;++i){
			ll t=vl[i];
			G0[i]=g0sum(t);
			(G0[i]+=mod-1)>=mod?G0[i]-=mod:0;
			G1[i]=g1sum(t);
			(G1[i]=1-G1[i]+mod)>=mod?G1[i]-=mod:0;
		}
		for(int k=1;k<=pn;++k){
			for(int i=1;i<=cnt;++i){
				ll t=vl[i];
				if(ll(p[k]*p[k])>t)break;
				int id=idx(t/p[k]);
				(G0[i]=G0[i]-ll(g0(p[k]))*(G0[id]-G0p[k-1]+mod)%mod+mod)>=mod?G0[i]-=mod:0;
				(G1[i]=G1[i]-ll(g1(p[k]))*(G1[id]-G1p[k-1]+mod)%mod+mod)>=mod?G1[i]-=mod:0;
			}
		}
	}
	void init(ll x){
		n=x;
		sn=sqrt(n);
		while((sn+1)*(sn+1)<=n)++sn;
		li.resize(sn+5),gi.resize(sn+5),vl.resize((sn<<1)+5);
		getprime(sn+1000);
		cnt=0;
		ll l=1;
		while(l<=n){
			ll t=n/l,r=n/t;
			if(t<=sn)li[t]=++cnt;
			else gi[r]=++cnt;
			vl[cnt]=t;
			l=r+1;
		}
		calcprime();
	}
	int f_p(ll x){
		x%=mod;
		return (x*x-x+mod)%mod;
	}
	int F(int k,ll x){
		if(p[k]>x||x<=1)return 0;
		int id=idx(x);
		int res=(ll(G0[id])+G1[id]-G0p[k-1]+mod-G1p[k-1]+mod)%mod;
		for(int i=k;i<=pn;++i){
			ll v=ll(p[i])*p[i];//may n^1.5
			if(v>x)break;
			ll pw=p[i];
			while(v<=x){
				res=(res+ll(f_p(pw))*F(i+1,x/pw)+f_p(v))%mod;
				pw=v;
				v*=p[i];
			}
		}
		return res;
	}
	int F(ll x){
		return (F(1,x)+1)%mod;
	}
};