#include <bits/stdc++.h>

using namespace std;

/*

Author - Player__

*/
typedef long long ll;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef __int128 lll;


int main(){

    fast_io

    int tt;cin>>tt;

    while(tt--){
int n;ll k;

     cin>>n>>k;
     vector<ll> a(n+2);
     for(int i=1;i<=n;i++){
      cin>>a[i];
     }
     vector<ll> h(n+2,0);
     for(int i=2;i<=n;i++){
        ll d=a[i]-a[i-1];
        h[i]=h[i-1]+(k-d);
     }
     vector<lll> s(n+2,0);
        for(int i=1;i<=n;i++) s[i]=s[i-1]+(lll)h[i];

        vector<ll> an(n+2,0);
        for(int i=2;i<=n-1;i++){
            ll d=a[i+1]-a[i-1];
            if(d<=k) continue;

            ll e=d-k;
            ll c=e+h[i+1];
            int l=i+1;int r=n;int p=n+1;
            while(l<=r){
                int m=(l+r)>>1;
                if(h[m]>=c){p=m;r=m-1;}
                else l=m+1;
            }
            int u=p-1;
            ll cnt=u-i;
            lll sh=s[u]-s[i];
            lll res= (lll)cnt*(lll)c-sh;
            an[i]=(ll)res;
        }
        for(int i=1;i<=n;i++) cout<<an[i]<<" ";
        cout<<"\n";

    }
    return 0;
}


