#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
int main (){
    fast_io
    int n;
    ll w;
    cin >> n >> w;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll bs = 0;
    for(int m = 0; m < (1 << n); m++){
        ll val = 0, vol = 0;
        for(int i = 0; i < n; i++){
            if(m >> i & 1){
                val += a[i];
                vol += b[i];
            }
        }
        if(vol <= w) bs = max(bs, val);
    }
    cout << bs << "\n";
    return 0;
}