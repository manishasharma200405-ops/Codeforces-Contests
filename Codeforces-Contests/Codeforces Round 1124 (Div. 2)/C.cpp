#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;

int main(){
  fast_io
int t; cin>>t;
    while(t--){
int n,k; cin>>n>>k;
vector<ll> a(n);
for(int i=0;i<n;i++) cin>>a[i];

if(k>n){
 cout<<0<<"\n";
    continue;
        }
if(k==1){
     ll res=0;
for(int i=0;i<n;i++) res+=a[i];
    cout<<res<<"\n";
    continue;
        }

 ll ans=0;
 if(n<=2*k-1){
    int o=n-k+1;
for(int j=0;j<o;j++){
     int ia=k-1+j;
         int ib=n-k-j;
    if(ia==ib) ans+=a[ia];
    else ans+=max(a[ia],a[ib]);
            }
        } else {
  int l=k-1;
      ll res=0;
for(int i=0;i<n;i++) res+=a[i];
 int n2=2*l;
     for(int j=0;j<l;j++){
     int ia=k-1+j;
         int ib=n2-k-j;
        auto val=[&](int idx)->ll{
        if(idx<l) return a[idx];
        else return a[n-l+(idx-l)];
                };
    res -= min(val(ia), val(ib));
            }
            ans = res;
        }
 cout<<ans<<"\n";
    }
    return 0;
}