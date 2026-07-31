//ARC
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
//macros
#define rep(i,n) for(int i=1; i<=n; i++)
#define rep1(i,a,b) for(int i=(a); i<=(b); i++)

#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>

void sv() {
    int n;
    cin >> n;
    vi p(n + 1);
    rep(i,n) cin >> p[i];

    vector<bool> vis(n + 1, false);
    ll ans = 0;
    int i = 1;
    while (i <= n) {
        if (vis[i]) { i++; continue; }
        int r = i, j = i;
        while (j <= r) {
            r = max(r, p[j]);
            j++;
        }
        for (int k = i; k <= r; k++) {
            if (vis[k]) continue;
            int c = 0, cur = k;
            while (!vis[cur]) {//visting cur 
                vis[cur] = true;
                cur = p[cur];
                c++;
            }
            if (c > 1) ans++;
        }
        i = r + 1;
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    sv();
    return 0;
}