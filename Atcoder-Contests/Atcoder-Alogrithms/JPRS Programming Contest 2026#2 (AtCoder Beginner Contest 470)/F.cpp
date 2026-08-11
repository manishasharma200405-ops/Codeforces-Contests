#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
const ll mod = 998244353;
int par[200005];
int fnd(int x){ return par[x]==x ? x : par[x]=fnd(par[x]); }

ll fact[200005], invf[200005];
ll pw(ll a, ll b){ ll r=1; a%=mod; for(;b;b>>=1,a=a*a%mod) if(b&1) r=r*a%mod; return r; }
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
  fast_io;
    int n,m; cin>>n>>m;
    string s; cin>>s;
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=0;i<m;i++){ int a,b; cin>>a>>b; par[fnd(a)]=fnd(b); }

    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
    invf[n]=pw(fact[n],mod-2);
    for(int i=n;i>0;i--) invf[i-1]=invf[i]*i%mod;

    vector<array<int,26>> cnt(n+1, array<int,26>{});
    vector<int> sz(n+1,0);
    for(int i=1;i<=n;i++){ int r=fnd(i); sz[r]++; cnt[r][s[i-1]-'a']++; }

    ll t=1; bool rep=false;
    for(int i=1;i<=n;i++){
        if(fnd(i)!=i) continue;
        int k=sz[i]; ll tc=fact[k]; bool r2=false;
        for(int c=0;c<26;c++) if(cnt[i][c]){ tc=tc*invf[cnt[i][c]]%mod; if(cnt[i][c]>1) r2=true; }
        t=t*tc%mod;
        if(k>=2 && r2) rep=true;
    }
    return 0;
}
 