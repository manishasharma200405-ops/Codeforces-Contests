#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main (){
    fast_io

   int n,q;
    cin>>n>>q;
    vector<ll> l(n+2),r(n+2);
    for(int i=2;i<=n;i++)cin>>l[i];
    for(int i=1;i<n;i++)cin>>r[i];
    const ll inf=4e18;
    vector<ll> pm(n+2,inf),sm(n+2,inf);
    for(int i=1;i<n;i++)pm[i]=min(pm[i-1],r[i]);
    for(int i=n;i>=2;i--)sm[i]=min(sm[i+1],l[i]);
    while(q--){
        int s,t;
        cin>>s>>t;
        ll ans;
        if(s<t){
            ans=r[s];
            if(s>=2)ans=min(ans,l[s]+pm[s-1]);
        }
        else{
            ans=l[s];
            if(s<n)ans=min(ans,r[s]+sm[s+1]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}