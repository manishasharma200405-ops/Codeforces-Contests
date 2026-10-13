#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int nxt(int x){
    int s=0;
    while(x){
        int d=x%10;
        s+=d*d;
        x/=10;
    }
    return s;
}

int main (){
    fast_io
 int t;
    cin>>t;

    while (t--) {
        int n;
        cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

     unordered_map<int,int> cnt;
    for(int i=0;i<n;i++){
    int x = a[i];
    for(int s=0;s<2000;s++) x = nxt(x);
    cnt[x]++;
        }

ll ans = 0;
for(auto &p : cnt){
     ll c = p.second;
     ans += c*(c-1)/2;
        }
    cout << ans << "\n";
    }

    return 0;
}