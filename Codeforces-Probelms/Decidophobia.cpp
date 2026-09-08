#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int tt;cin>>tt;
  while(tt--){
    int n ,d;cin>>n>>d;
    vector<ll> a(n*3),s(n*3+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i+n]=a[i];
        a[i+2*n]=a[i];
    }
    //happi. is nota num.  of gifts cal a score of every person  gits is nothing but just x[i] belongs to {1,0}
    ll ans =0;
    
   for(int i=0;i<3*n;i++){
    s[i+1]=s[i]+a[i];
   }

   for(int i=0;i<n;i++){
    int p=i+n;
    ll w= 2LL *d*a[i];
    w-=s[p]-s[p-d];
    w-=s[p+d+1]-s[p+1];
    ans+=max(0LL,w);

   }
   cout<<ans<<"\n";
  }
    return 0;
}