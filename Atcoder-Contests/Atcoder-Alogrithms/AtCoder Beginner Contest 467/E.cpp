//ABC 467 
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
//#define rep(i,b) for(int i=0;i<=b;i++)
//#define rep1(i,a,b) for(int i=a;i<=b;i++)
//#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; ll m;
    cin>>n>>m;
    
    vector<ll> a(n + 5);
    fori(i,0,n) cin >> a[i];
    
    vector<ll> b(n + 5);
    fori(i,0,n-1) cin >> b[i];

    vector<ll> c(n + 5);
    fori(i,0,n-1){
        c[i] = ((b[i]-a[i]-a[i+1])%m+m)%m;
    }

    vector<ll> d(n + 5);
    vector<int> g(n + 5);
    d[0]=0; g[0]=1;
    fori(i,1,n){
        d[i] = ((c[i-1]-d[i-1])%m+m)%m;
        g[i] = -g[i-1];
    }

    ll s=0, k=0;
    fori(i,0,n){ s+=d[i]; k+=g[i]; }

    vector<pair<ll,ll>> e; 
    fori(i,0,n){
        if(g[i]==1){
            if(d[i]>0){
                e.push_back({m - d[i], -m});
            }
        } else {
            if(d[i] < m-1){
                e.push_back({d[i]+1, m});
            }
        }
    }
    sort(e.begin(), e.end());

    ll v = s;
    ll x = v;
    ll p = 0;

    size_t j=0;
    while(j < e.size()){
        ll t = e[j].first;
        ll d_s=0;
        while(j<e.size() && e[j].first==t){//d_s =e[j].second;
            d_s += e[j].second;
            j++;
        }
        if(t-1 >= p){
            //x=min(x,v+(t-1-p));
            x = min(x, v + k*(t-1-p));
        }
        //v=v+d_s+(t-p)
        v=v+k*(t-p)+d_s;
        x = min(x, v);
        p = t;
    }
    if(m-1 >= p){
        x = min(x, v + k*(m-1-p));
    }

    cout << x << '\n';

    return 0;
}
