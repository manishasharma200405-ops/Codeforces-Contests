#include <bits/stdc++.h>
/*
  Player__
*/
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    fast_io;
    int tt;cin>>tt;
      while(tt--){
       int n;cin>>n;
       vector<ll> a(n);//gcd after diff is generated 
       //what range of the diff arr  corresponds to subarray of a .
       for(auto &x:a) cin>>x;
       if(n==1){
         cout<<1<<"\n"; continue;
       }
       vector<ll> diff(n-1);
       for(int i=0;i<n-1;i++){
        diff[i]=abs(a[i+1]-a[i]);

       }
       int sz=n-1;
       vector<int> lg(sz+1);
       for(int i=2;i<=sz;i++){
        lg[i]=lg[i/2]+1;
       
        
       }
       int K=lg[sz]+1;

       vector<vector<ll>> st(K,vector<ll>(sz));
       for(int i=0;i<sz;i++){
        st[0][i]=diff[i];
       }
       for(int k=1;k<K;k++){
        for(int i=0;i+(1<<k)<=sz;i++){
            st[k][i]=gcd(
                st[k-1][i],
                st[k-1][i+(1<<(k-1))]
            );
        }
       }
       auto gt_gcd=[&](int l,int r)-> ll{
        int len =r-l+1;
        int k=lg[len];
        return gcd(st[k][l],
        st[k][r-(1<<k)+1]);
       };
           int ans=1;
           for(int l=0;l<sz;l++){
            if(diff[l]==1) continue ;
            int lo=l;
            int hi=sz-1;
            int bt=l;
            while(lo<=hi){
                int mid =(lo+hi)/2;
                if(gt_gcd(l,mid)>1){
                    bt=mid;lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
            ans=max(ans,bt-l+2);

            
           }
           cout<<ans<<"\n";

      }
return 0;
}