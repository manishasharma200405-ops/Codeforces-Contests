#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const int LG=20;
int S;
vector<ll> fc, fs;

void up(int i, ll c, ll s){
    for(;i<=S;i+=i&(-i)){fc[i]+=c; fs[i]+=s;}
}
ll qc(int i){ll r=0; for(;i>0;i-=i&(-i)) r+=fc[i]; return r;}
ll qs(int i){ll r=0; for(;i>0;i-=i&(-i)) r+=fs[i]; return r;}

ll qr(ll V){//using  binary lifting query (fenwick tree power of 2 jumps )
    if(V<=0) return 0;
    int p=0; ll sm=0, cn=0;
    for(int i=LG;i>=0;i--){
        int nx=p+(1<<i);
        if(nx<=S && sm+fs[nx]<V){
            p=nx; sm+=fs[nx]; cn+=fc[nx];
        }
    }
    if(p==S) return -1;
    ll pc=qc(p+1), ps=qs(p+1);
    ll ca=pc-cn, sa=ps-sm;
    ll vl=sa/ca;
    ll nd=V-sm;
    ll tk=(nd+vl-1)/vl;
    return cn+tk;
}

int main(){
    fast_io
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        vector<int> a(n*m);
        for(int i=0;i<n*m;i++) cin>>a[i];

        vector<int> vs(a.begin(), a.end());
        sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        S=vs.size();
        fc.assign(S+1,0);
        fs.assign(S+1,0);

        auto id=[&](int x)->int{
            int p = lower_bound(vs.begin(), vs.end(), x) - vs.begin() + 1;
            return S - p + 1;
        };

        ll bs=-1;
        for(int k=n;k>=1;k--){
            int b=(k-1)*m;
            for(int j=0;j<m;j++){
                int vl=a[b+j];
                int d=id(vl);
                up(d, 1, vl);
            }
            ll rs=qr(v[k]);
            if(rs>=0 && (bs==-1||rs<bs)) bs=rs;
        }
        ll ans=m;
        if(bs!=-1 && bs<ans) ans=bs;
        cout<<ans<<"\n";
    }
}