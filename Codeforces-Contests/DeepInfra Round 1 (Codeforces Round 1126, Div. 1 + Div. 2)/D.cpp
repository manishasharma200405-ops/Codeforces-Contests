#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;

ll m,k;
vector<ll>l,r,pf;

ll c(ll x){
    int id=upper_bound(l.begin(),l.end(),x)-l.begin();
    if(id==0)return 0;
    int j=id-1;
    return pf[j]+min(x,r[j])-l[j]+1;
}

ll f(ll s){
    return c(s+m-1)-c(s-1);
}

int main (){
    fast_io

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n>>m>>k;
        l.assign(n,0);
        r.assign(n,0);
        pf.assign(n+1,0);
        for(int i=0;i<n;i++){
            cin>>l[i]>>r[i];
            pf[i+1]=pf[i]+r[i]-l[i]+1;
        }
        vector<ll>ps;
        ps.push_back(1);
        for(int i=0;i<n;i++){
            ll cd[4]={l[i],r[i]+1,l[i]-m,r[i]+1-m};
            for(int q=0;q<4;q++)if(cd[q]>=1)ps.push_back(cd[q]);
        }
        sort(ps.begin(),ps.end());
        ps.erase(unique(ps.begin(),ps.end()),ps.end());
        int z=ps.size();
        vector<ll>fv(z);
        for(int i=0;i<z;i++)fv[i]=f(ps[i]);
        ll ans=-1;
        for(int i=0;i+1<z&&ans<0;i++){
            ll a=ps[i];
            ll fa=fv[i],fe=fv[i+1];
            if(fa==fe){
                if(fa==k)ans=a;
            }else if(fe>fa){
                if(k>=fa&&k<=fe)ans=a+(k-fa);
            }else{
                if(k<=fa&&k>=fe)ans=a+(fa-k);
            }
        }
        if(ans<0&&fv[z-1]==k)ans=ps[z-1];
        cout<<ans<<"\n";
    }

    return 0;
}