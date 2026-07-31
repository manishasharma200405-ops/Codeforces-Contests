//ARC
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;

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

    ll ans = 0;
    rep(i,n) ans += llabs((ll)p[i] - i);
    ans /= 2;

    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    sv();
    return 0;
}