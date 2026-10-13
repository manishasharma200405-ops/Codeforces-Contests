#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll ;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
       int n;ll x;cin>>n>>x;
       vector<int> a(n);
 for (int i=0;i<n;i++) cin>>a[i];
   vector<ll> prm;// first we find prm factors. of x liek x is prirate num..for steal coins form treasury ...
   ll y=x;
   for(ll i=2;i*i<=y;i++){
    if(y%i==0){
        prm.push_back(i);
        while(y %i==0) y/=i;
    }
   }
   if(y>1 ) prm.push_back(y);
   ll ans=0;
   for(ll i:prm){
    ll sum=0;
    for(int j=0;j<n;j++){
        if(a[j]%i==0) sum+=a[j];
    }
    ans=max(ans,sum);
   }
    cout<<ans<<"\n";
    }
    return 0;
}