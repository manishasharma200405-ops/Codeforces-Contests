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
   int n,m;cin>>n>>m;
 
        ll a, b;
        cin >> a;

        for(int i = 1; i < n; i++) {
            ll x;
            cin >> x;
        }

        cin >> b;

        for(int i = 1; i < m; i++) {
            ll x;
            cin >> x;
        }

        ll be = b + m - 1;
        ll vr = a + n - 1;

        if(be <= vr)
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }

    return 0;
}