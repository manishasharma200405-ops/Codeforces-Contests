

#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back


int main(){
    

    int tt; cin >> tt;
    while(tt--){
         ll n, k; cin >> n >> k;
        ll p = 1; while(p < n) p <<= 1;

        bool v = (p == n) ? (k >= n && k <= 2*n - 1) : (k >= 0 && k <= p - 1);
        if(!v){ cout << "NO\n"; continue; }
// int m=k ^ n;
        ll t = k ^ n;
        vector<ll> m;
        rep(b, 31) if((t >> b) & 1) m.pb(1LL << b);

        int n2 = (int)n;
        vector<char> mil(n2, 0);
        for(ll v : m) mil[(int)v] = 1; 

        vector<ll> a(n2);
        int pos = 0;
        rep1(v, 1, n2-1) if(!mil[v]) a[pos++] = v;
//a[pos++]=1;
        a[pos++] = 0;
        for(ll v : m) a[pos++] = v;
        //cout<<a[pos];

        cout << "YES\n";
        rep(i, n2) cout << a[i] << " \n"[i == n2 - 1];
    
        }    return 0;
}
