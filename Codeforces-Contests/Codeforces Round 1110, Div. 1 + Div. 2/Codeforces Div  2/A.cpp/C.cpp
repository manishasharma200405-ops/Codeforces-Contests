//Div 2
#include <bits/stdc++.h>
using namespace std;

/*
Author - Kenway-Connor
*/
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)

const int N = 1e6+5;
const ll MOD = 998244353;

int a[N];
ll s[N];
bool u[N];
int n;
//cin >>h>>"\n";
ll go(int k){
    static vector<int> lv, rv, tc;
    lv.clear(); rv.clear(); tc.clear();

    int pm = 0;
    rep1(i,1,k){ if(a[i] > pm){ lv.pb(a[i]); pm = a[i]; } }

    pm = 0;
    repd(i,n-1,k+1){ if(a[i] > pm){ rv.pb(a[i]); pm = a[i]; } }

    bool cf = false;
    for(int v : lv){ u[v] = true; tc.pb(v); }
    for(int v : rv){
        if(u[v]) cf = true;
        else { u[v] = true; tc.pb(v); }
    }

    ll rs = 0;
    if(!cf){
        ll rn = 0, t = 0, pr = 1;
        bool bd = false;
        repd(v,n-2,1){
            rn += u[v+1] ? 1 : 0;
            if(bd) continue;
            if(!u[v]){
                t++;
                ll S = s[v] - rn;
                ll fc = S - (t-1);
                if(fc < 0){ bd = true; continue; }
                pr = (pr * (fc % MOD)) % MOD;
            }
        }
        rs = bd ? 0 : pr;
    }

    for(int v : tc) u[v] = false;
    return rs;
}
//using void solve for better understanding 
void solve(){
    cin >> n;
    rep1(i,1,n-1) cin >> a[i];

    rep1(i,0,n-1) s[i] = 0;
    rep1(i,1,n-1) s[a[i]]++;

    ll rn = 0;
    for(int v = n-1; v >= 0; v--){
        ll f = s[v];
        s[v] = rn;
        rn += f;
    }

    int hi = 1;
    rep1(i,2,n-1){ if(a[i] >= a[i-1]) hi = i; else break; }

    bool ok = true;
    rep1(i,hi+1,n-1){ if(a[i] > a[i-1]){ ok = false; break; } }
    if(ok && a[hi] != n-1) ok = false;

    ll ans = 0;
    if(ok){
        int lo = hi;
        while(lo > 1 && a[lo-1] == a[hi]) lo--;
        ans = (go(lo-1) + go(hi)) % MOD;
    }

    cout << ans << "\n";
}

int main(){
  
    int tt; cin >> tt;
    while(tt--){
        solve();
    }
}