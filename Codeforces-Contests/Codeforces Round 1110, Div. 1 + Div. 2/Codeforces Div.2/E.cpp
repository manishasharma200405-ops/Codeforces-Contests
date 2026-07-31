//div2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
typedef unsigned long long ull;

//#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,b) for(int i=0; i<=(b); i++)
#define rep1(i,a,b) for(int i=(a); i<=(b); i++)

ull SEED;
ull splitmix64(ull x){
    x += 0x9E3779B97F4A7C15ULL;
    x = (x ^ (x >> 30)) * 0xBF58476D1CE4E5B9ULL;
    x = (x ^ (x >> 27)) * 0x94D049BB133111EBULL;
    return x ^ (x >> 31);
}
ull tag(ll v){ return splitmix64((ull)v ^ SEED); }

ll solveState(vector<ll> &a){
    int n = a.size();
    vector<ll> target = a;
    sort(target.begin(), target.end());

    vector<ull> curPre(n+1,0), tgtPre(n+1,0);
    rep1(i,0,n-1){
        curPre[i+1] = curPre[i] + tag(a[i]);
        tgtPre[i+1] = tgtPre[i] + tag(target[i]);
    }

    int LOG = 0; while((1<<LOG) < n) LOG++;
    rep1(t,0,LOG){
        int sz = 1<<t;
        bool ok = true;
        for(int l=0; l<n && ok; l+=sz){
            int r = min(l+sz, n);
            if(curPre[r]-curPre[l] != tgtPre[r]-tgtPre[l]) ok=false;
        }
        if(ok) return (t==0) ? 0LL : (1LL<<(t-1));
    }
    return -1;
}

int main(){
int tt;
 cin >> tt;

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    SEED = rng();

    while(tt--){
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        rep1(i,0,n-1) cin >> a[i];

        cout << solveState(a) << "\n";
        rep(i, q-1){
            int idx; ll x;
            cin >> idx >> x;
            a[idx] = x;
            cout << solveState(a) << "\n";
        }
    }

    return 0;
}