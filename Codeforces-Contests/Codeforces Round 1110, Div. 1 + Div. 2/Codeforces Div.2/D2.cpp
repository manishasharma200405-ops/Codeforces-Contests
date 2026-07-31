//div2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;

//#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,b) for(int i=0; i<=(b); i++)
#define rep1(i,a,b) for(int i=(a); i<=(b); i++)
// upsolving ---> an editorial soln. 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rsv reverse
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define ff first
#define ss second

#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>

void sv() {
    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, n - 1) cin >> a[i];

    int m = 1;
    while (m < n) m *= 2;
    while (n < m) {
        a.pb(1e9);
        n++;
    }

    vector<array<int, 3>> t(2 * n);
    vi d(2 * n, 1);

    rep(j, n - 1) t[n + j] = {a[j], a[j], 0};

    auto pl = [&](int j, int l) {
        t[j][0] = min(t[j << 1][0], t[j << 1 | 1][0]);
        t[j][1] = max(t[j << 1][1], t[j << 1 | 1][1]);
        //t[j][2]=min(t[j<<1] [1] , t[j << 1] [0]);
        t[j][2] = max(t[j << 1][2], t[j << 1 | 1][2]);
        if (t[j << 1][1] > t[j << 1 | 1][0]) t[j][2] = max(t[j][2], l / 2);
    };

    for (int j = n - 1; j >= 1; j--) {//d[j]=2*d[j];
        d[j] = 2 * d[j << 1];
        pl(j, d[j]);
    }

    cout << t[1][2] << '\n';

    while (q--) {
        int p, x; cin >> p >> x;
        p += n;
        t[p] = {x, x, 0};
        p >>= 1;
        int l = 2;
        while (p) {
            pl(p, l);
            p >>= 1;
            l *= 2;
        }
        cout << t[1][2] << '\n';
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