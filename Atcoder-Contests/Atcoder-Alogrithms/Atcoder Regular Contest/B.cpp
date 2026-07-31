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



#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>

// g(0)=0 and g(n)=n;
//  inline int gv(int l) {
//     if (l == 0) return 0;
//     if (l == 1) return 1;
//     if (l == 2) return 0;
//     return l - 1;
// }

void sv() {
    int n; cin >> n;
    vi a(n);
    rep(i, n - 1) cin >> a[i];

    bool al = false;
    int rn = 0;
    rep(i, n - 1) {
        if (a[i] == 1) {
            rn++;
        } else {
            if (rn != 0 && rn != 2) al = true;
            rn = 0;
        }
    }
    if (rn != 0 && rn != 2) al = true;

    cout << (al ? "Alice" : "Bob") << '\n';
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