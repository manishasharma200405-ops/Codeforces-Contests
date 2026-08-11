#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define fi first
#define se second

void solve(){
    int n,q;
    cin>>n>>q;
    vector<ll> v(n+2,0);
    vector<int> nx(n+2,0), pv(n+2,0);
    int D=0;
    nx[D]=D; pv[D]=D;
    ll xr=0;

    rep(_,q){
        int op; cin>>op;
        if(op==1){
            int x; cin>>x;
            xr^=v[x];
            v[x]++;
            xr^=v[x];
            if(v[x]==1){
                int a=D,b=nx[D];
                nx[a]=x; pv[x]=a;
                nx[x]=b; pv[b]=x;
            }
        } else {
            int c=nx[D];
            while(c!=D){
                int nt=nx[c];
                xr^=v[c];
                v[c]--;
                if(v[c]==0){
                    int a=pv[c],b=nt;
                    nx[a]=b; pv[b]=a;
                } else xr^=v[c];
                c=nt;
            }
        }
        cout<<xr<<"\n";
    }
}

int main(){
 fast_io
    solve();
}