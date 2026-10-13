#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll ;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
int t;cin>>t;
 while(t--){
 int n; cin >> n;
        vector<ll> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
/*
given a func do mex ...
*/
        vector<int> diff(n+2, 0);
 for(int k = 1; k <= n; k++){
            ll l = a[k] * (ll)k;
            if(l >= n) continue;
            ll r = min((a[k]+1)*(ll)k - 1, (ll)n - 1);
            diff[l]++;
            diff[r+1]--;
        }
 vector<int> b;
 int run = 0;
        for(int i = 0; i < n; i++){
            run += diff[i];
            if(run == 0) b.push_back(i);
        }

             cout << b.size() << "\n";
 for(int i = 0; i < (int)b.size(); i++){
            cout << b[i] << " \n"[i+1==(int)b.size()];
        }
        if(b.empty()) cout << "\n";
    }
 




  

return 0;
}