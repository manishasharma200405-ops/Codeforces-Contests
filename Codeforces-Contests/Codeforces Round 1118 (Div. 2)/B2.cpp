#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
void slv(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    map<ll, int> cnt;
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

    sort(a.begin(), a.end());
    ll s = accumulate(a.begin(), a.end(), 0ll);
  
    for (int j = 1; j <= m; j++){
        if (j >= 19){
            cout << s << " ";
        }else{
            ll b = 0;
            for (int i = 1; ((1<<j)*i) <= m; i++){
                
                ll curr = 0;
                for (int k = i; k <= min(m, (1<<j) * i); k += i){
                    curr += a.end() - lower_bound(a.begin(), a.end(), k);
                }
                curr -= a.end() - lower_bound(a.begin(), a.end(), 1 + (1<<j)*i);
                b = max(b, curr);
            }
         
            cout << (b == 0 ? s : b) << " ";
        }
    }
    cout << "\n";
}


int main (){
    fast_io
int t;cin>>t;
 while(t--){
slv();
  
 }


  

return 0;
}