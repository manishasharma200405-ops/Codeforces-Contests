//div2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;

#define rep(i,b) for(int i=0; i<=(b); i++)
#define rep1(i,a,b) for(int i=(a); i<=(b); i++)
#define pb push_back
#define rsz resize
#define rsv reserve
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;

    while(tt--){
        ll n, k;
        cin >> n >> k;

        ll mn = 2*(n-1);//int max=(n*n)%2;
        ll mx = (n*n)/2;
       // k<mx && k>mn
        if(k < mn || k > mx){
            cout << -1 << "\n";
            continue;
        }

        ll ex = k - mn;

        vl sq;
        sq.rsv(n);

        ll lo = 1, hi = n, pv = -1;

        while(lo <= hi){
            if(lo == hi){
                sq.pb(lo); lo++; hi--; continue;
            }
            if(pv == -1){
                sq.pb(lo); pv = lo; lo++;continue;
            }
            ll df = llabs(pv - hi);
            ll dn = llabs(pv - lo);
            ll gf = df - dn;

            if(ex > 0 && gf > 0 && ex >= gf){
                sq.pb(hi);
                ex -= gf;
                pv = hi;
                hi--;
            } else {
                sq.pb(lo);
                pv = lo;
                lo++;
            }
        }

        vl ps(n+1), la(n+1);
        rep1(i,1,n) ps[i] = sq[i-1];
        rep1(i,1,n) la[ps[i]] = i;

        vector<pll> ed;
        ed.rsv(n-1);
        rep1(p,1,n-1) ed.pb({la[p], la[p+1]});

        for(auto &e : ed) cout << e.fi << " " << e.se << "\n";
    }

    return 0;
}