//ARC
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;

#define rep(i,b) for(int i=0; i<=(b); i++)
#define rep1(i,a,b) for(int i=(a); i<=(b); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pair<int,int>>
#define re reserve
#define uni unite

struct DSU {
    vi p, sz;
    DSU(int n): p(n+1), sz(n+1,1) {
        rep(i, n) p[i] = i;
    }
    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    bool uni(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

void sv() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vi a(m+1), b(m+1), c(m+1);
    rep1(i, 1, m) {
        cin >> a[i] >> b[i] >> c[i];
    }

    DSU d0(n);
    int r0 = 0;
    rep1(i, 1, m) {
        if (c[i] == 0) {
            if (d0.uni(a[i], b[i])) r0++;
        }
    }
    int c0 = n - r0;
    ll L = (ll)c0 - 1;

    DSU d1(n);
    vi f1;
    rep1(i, 1, m) {
        if (c[i] == 1) {
            if (d1.uni(a[i], b[i])) f1.pb(i);
        }
    }
    ll U = (ll)f1.size();

    if (k < L || k > U) {
        cout << -1 << "\n";
        return;
    }

    vi es, op;
    es.re(f1.size());
    op.re(f1.size());
    for (int id : f1) {
        if (d0.uni(a[id], b[id])) {
            es.pb(id);
        } else {
            op.pb(id);
        }
    }

    vi ans;
    ans.re(n-1);
    for (int id : es) ans.pb(id);
    ll req = k - L;
    for (ll i = 0; i < req; i++) ans.pb(op[i]);

    DSU df(n);
    for (int id : ans) df.uni(a[id], b[id]);

    ll nd = (ll)(n-1) - k;
    ll cnt = 0;
    for (int i = 1; i <= m && cnt < nd; i++) {
        if (c[i] == 0) {
            if (df.uni(a[i], b[i])) {
                ans.pb(i);
                cnt++;
            }
        }
    }

    rep(i, (int)ans.size() - 1) {
        cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--) {
        sv();
    }
    return 0;
}
