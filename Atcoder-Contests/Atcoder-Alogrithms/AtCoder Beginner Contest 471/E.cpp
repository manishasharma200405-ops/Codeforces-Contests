#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll ;
const ll MOD =998244353;
ll pow (ll a,ll b, ll c){
    a%=c;if(a<0) a+=c;
    ll res=1;
    while(b>0){
        if(b&1) res=res*a%c;
        a=a*a%c;
        b>>=1;
    }
    return res;
}
int main (){
    fast_io
int n;cin>>n;
int k;cin>>k;
vector<ll> a(n);
for( auto &x:a)cin>>x;
int mxn=(int )n+5;
vector<ll> fac(mxn),iv(mxn);
fac[0]=1;
for(int i=1;i<mxn;i++){
    fac[i]=fac[i-1]*i%MOD;

}
iv[mxn-1]=pow(fac[mxn-1],MOD-2,MOD);
for(int i=mxn-2;i>=0;i--) iv[i]=iv[i+1]*(i+1)%MOD;
auto c=[&] (ll n,ll r)->ll{
    if(r<0||n<0||r>n) return 0;
    return fac[n]*iv[r]%MOD*iv[n-r]%MOD;
};
ll s1=0,s2=0;
for(ll i:a){
    ll an=i%MOD;
    s1=(s1+an)%MOD;
    s2=(s2+an*an)%MOD;

}
ll term =c(n-1,k-1)*s2%MOD;
ll diff=((s1*s1%MOD)-s2%MOD +MOD)%MOD;
ll t2=c(n-2,k-2)*diff%MOD;
ll ans =(term+t2)%MOD;
cout<<ans<<"\n";
 
    return 0;
}