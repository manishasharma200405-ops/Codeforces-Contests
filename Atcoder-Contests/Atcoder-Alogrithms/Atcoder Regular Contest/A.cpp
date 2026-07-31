//ARC
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

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    vvi x(n, vi(n));
    rep(i, n - 1) rep(j, n - 1) cin >> x[i][j];

    // phi: 1->3, 2->1, 3->4, 4->2
    int f[5] = {0, 3, 1, 4, 2};

    rep(i, n - 1) {
        rep(j, n - 1) {
            cout << f[x[i][j]] << " \n"[j == n - 1];
        }
    }

    return 0;
}