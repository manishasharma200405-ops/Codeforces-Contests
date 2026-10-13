
//Fair and Square
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
typedef vector<ll> vll;
#define forn(i, n) rep(i, 0, n)
#define each(a, x) for (auto &a : x)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

const int MAXN = 2e5 + 5; 
ll ss[MAXN];

template<typename T> istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) in >> x; return in;
}
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    for (int i = 0; i < sz(v); ++i) out << v[i] << (i == sz(v) - 1 ? "" : " "); return out;
}

int main(){
    

    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        
        vll a(n);
        forn(i, n) cin >> a[i];
        forn(i, n + 1) ss[i] = 1;

        vector<vll> e(n);
        forn(i, n - 1){
            ll q, p;
            cin >> q >> p;
            q--; p--;
            e[q].push_back(p);
            e[p].push_back(q);
        }
        ll ans = 0;
        //vll val;
        function<void(ll, ll)> dfs = [&](ll u, ll p){
            vll val;
            each(z, e[u]){
                if(z != p){
                    dfs(z, u);
                    val.push_back(ss[z]);
                    ss[u] += ss[z];
                }
            }
            val.push_back(n - ss[u]);
            assert(accumulate(all(val), 0ll) == n - 1);
            if((ll)sqrtl(a[u]) * (ll)sqrtl(a[u]) < a[u]) return ;

            ll sum = 0; ll pair = 0; ll trip = 0;
            each(z, val){
                trip += pair * z;
                pair += sum * z;
                sum += z;
            }
            ans += pair;
            ans += trip;
        };
        dfs(0, -1);
        cout << ans << "\n";
    }    
    return 0;
}
