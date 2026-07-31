//ABC 467
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/

typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,b) for(int i=0;i<=b;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define lb lower_bound
const ll NEG = -4e18;

int main(){
   

    int n, q;
    cin>>n>>q;

    vector<ll> a(n + 5), b(n + 5);
    rep1(i, 1, n) cin >> a[i];
    rep1(i, 1, n) cin >> b[i];

    vector<int> t(q), id(q);
    vector<ll> x(q);
    fori(i, 0, q) {
        cin >> t[i] >> id[i] >> x[i];
    }

    vector<ll> v;
    v.reserve(n + q);
    rep1(i, 1, n) v.pb(b[i] * (ll)(n + 1) + i);
    fori(i, 0, q) {
        if (t[i] == 2) {
            //v.pb(x[i]*(n+1)+id[i]);
            v.pb(x[i] * (ll)(n + 1) + id[i]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int k = v.size();

    auto gp = [&](ll val, int idx) -> int {
        ll key = val * (ll)(n + 1) + idx;
        int p = lb(v.begin(), v.end(), key) - v.begin();
        return k - p;
    };

    int z = 1; 
    while (z < k) z <<= 1;
    vector<ll> sm(2 * z, 0), mx(2 * z, NEG);

    auto pull = [&](int u) {
        sm[u] = sm[2 * u] + sm[2 * u + 1];
        ll rm = mx[2 * u + 1];
        ll cd = (rm == NEG) ? NEG : (rm + sm[2 * u]);
        mx[u] = max(mx[2 * u], cd);
    };

    auto upd = [&](int p, ll sa, ll mv) {
        int u = z + p - 1;
        //  sm[u] = u; 
        sm[u] = sa; 
        mx[u] = mv;
        //u^1
        u >>= 1;
        while (u >= 1) { pull(u); u >>= 1; }
    };

    vector<int> pb(n + 5);
    rep1(i, 1, n) {
        int p = gp(b[i], i);
        pb[i] = p;
        upd(p, a[i], a[i] + b[i]);
    }

    fori(j, 0, q) {
        int ty = t[j], i = id[j]; ll val = x[j];
        if (ty == 1) {
            a[i] = val;
            int p = pb[i];
            upd(p, a[i], a[i] + b[i]);
        } else {
            int op = pb[i];
            upd(op, 0, NEG);
            b[i] = val;
            int np = gp(b[i], i);
            pb[i] = np;
            upd(np, a[i], a[i] + b[i]);
        }
        cout << mx[1] << '\n';
    }

    return 0;
}
