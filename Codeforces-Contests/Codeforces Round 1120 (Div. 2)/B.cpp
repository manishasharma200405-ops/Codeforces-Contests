#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
int t;cin>>t;
 while(t--){
  ll n, k;
        cin >> n >> k;

        if(k < n || k > 2*n-1){
            cout << "-1" << "\n";
            continue;
        }
/*
all other cell rmeain and largest num never become min.
.. tihs was need ed 
*/
ll O = 2*n - k;
 ll tt, m;
 if(O == n){
 tt = n; m = 0;
 } else {
    tt = O - 1;
 m  = n - tt;
        }

 vector<vector<ll>> a(n, vector<ll>(n, 0));
 ll val = 1;

 for(ll i = 0; i < tt; i++){
 a[i][i] = val++;
        }

if(m > 0){
     a[tt+m-1][tt+m-1] = val++;

 for(ll i = 0; i <= m-2; i++)
     a[tt+i][tt+m-1] = val++;

 for(ll j = 0; j <= m-2; j++)
         a[tt+m-1][tt+j] = val++;

 for(ll i = 0; i <= m-2; i++)
     for(ll j = 0; j <= m-2; j++)
         a[tt+i][tt+j] = val++;
        }

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                if(a[i][j] == 0) a[i][j] = val++;
            }
        }
 for(auto &v : a){
 for(auto y : v) cout << y << " ";
    cout << "\n";
        }
    }

  

return 0;
}