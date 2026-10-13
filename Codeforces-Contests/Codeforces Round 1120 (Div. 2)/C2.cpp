#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll md = 1000000007;

struct bit {
    vector<ll> t;
    int sz;
    void ini(int n){
        sz = n;
        t.assign(sz+2, 0);
    }
    void upd(int i, ll d){
        d %= md;
        if(d < 0) d += md;
        for(++i; i <= sz+1; i += i&(-i)){
            t[i] = (t[i] + d) % md;
        }
    }
    ll qry(int i){
        if(i < 0) return 0;
        ll s = 0;
        for(++i; i > 0; i -= i&(-i)) s = (s + t[i]) % md;
        return s;
    }
};
/*
exculsions df , ex cnt subsets such that every interval , in a family has at least 1 sel. pnts .....
*/
int main(){
    fast_io
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<ll> df(n+2, 0);
        for(int k = 1; k <= n; k++){
            ll l = a[k]*(ll)k;
            if(l >= n) continue;
            ll r = min((a[k]+1)*(ll)k - 1, (ll)n - 1);
            df[l]++;
            df[r+1]--;
        }

        vector<char> ex(n, 0);
        {
            ll rn = 0;
            for(int i = 0; i < n; i++){
                rn += df[i];
                ex[i] = (rn > 0);
            }
        }

        vector<int> nv(n, 0);
        for(int k = 1; k <= n; k++){
            ll ak = a[k];
            for(ll j = 0; j < ak; j++){
                ll l = j*(ll)k;
                ll r = min((j+1)*(ll)k - 1, (ll)(n-1));
                int x = (int)(l+1);
                int ri = (int)r;
                if(x > nv[ri]) nv[ri] = x;
            }
        }

        bit bt;
        bt.ini(n+1);
        vector<ll> vl(n+2, 0);
        vl[0] = 1;
        bt.upd(0, 1);
        int ct = 0;

        for(int c = 0; c < n; c++){
            int q = nv[c];
            ll tot = bt.qry(c);

            if(q > ct){
                for(int s = ct; s < q; s++){
                    if(vl[s] != 0){
                        bt.upd(s, md - vl[s]);
                        vl[s] = 0;
                    }
                }
                ct = q;
            }

            if(!ex[c]){
                vl[c+1] = tot;
                bt.upd(c+1, tot);
            } else {
                vl[c+1] = 0;
            }
        }

        ll an = bt.qry(n);
        cout << an << "\n";
    }


  

return 0;
}