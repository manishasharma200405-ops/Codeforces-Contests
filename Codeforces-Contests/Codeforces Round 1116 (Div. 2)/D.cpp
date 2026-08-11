#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
const ll MOD=998244353;
const int MX=1000006;
ll fact[MX],ifact[MX];

ll pw(ll a,ll b){ll r=1;
    a%=MOD;
    while(b){
        if(b&1)r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }return r;
}

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
//precompute fact 
    fact[0]=1;
    for(int i=1;i<MX;i++) fact[i]=fact[i-1]*i%MOD;
    ifact[MX-1]=pw(fact[MX-1],MOD-2);
    for(int i=MX-2;i>=0;i--) ifact[i]=ifact[i+1]*(i+1)%MOD;

int tt;cin>>tt;
while(tt--){
    int n; cin>>n;
    string buf; cin>>buf;

    ll N0=0,N1=0; int m0=0,m1=0,idx=0;
    int i=0;
    while(i<n){
        int j=i;
        while(j<n && buf[j]==buf[i]) j++;
        int len=j-i;
        if(idx%2==0){ N0+=len; m0++; }
        else { N1+=len; m1++; }
        idx++;
        i=j;
    }

    ll t0 = (m0==0)?1: fact[N0-1]*ifact[m0-1]%MOD*ifact[N0-m0]%MOD;
    ll t1 = (m1==0)?1: fact[N1-1]*ifact[m1-1]%MOD*ifact[N1-m1]%MOD;
    cout << t0*t1%MOD << "\n";
}
 
    
    return 0;
}