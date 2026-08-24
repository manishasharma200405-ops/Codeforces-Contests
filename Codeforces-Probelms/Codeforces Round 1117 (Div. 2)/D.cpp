#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll; 
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main (){
    fast_io
int t;cin>>t;

while(t--){
 
       
           ll s;
        cin >> s;

        int q;
        cin >> q;

        vector<ll> d;

        for(ll i = 1; i * i <= s; i++){
            if(s % i == 0){
                d.push_back(i);

                if(i * i != s){
                    d.push_back(s / i);
                }
            }
        }

        sort(d.begin(), d.end());

        while(q--){
            ll x, y;
            cin >> x >> y;

            ll ans = 0;
            ll prev = 0;

            for(ll v : d){
                if(prev >= x)
                    break;

   ll g = prev + 1;
                ll r = min(x, v);

                if(g <= r){
                    ll cnt = r - g + 1;
                    ll hgt = s / v;

                    ans += cnt * min(y, hgt);
                }

                prev = v;
            }

            cout << ans << "\n";
        }
    }

    return 0;
}