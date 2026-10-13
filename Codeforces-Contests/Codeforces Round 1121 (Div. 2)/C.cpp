#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
const ll mod=998244353;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll pw(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}

/*
sort the ratngs for vry skater i cal, the cost total of choosign each larger rating as its parnet , multipled by num of dnyasty ontianing rach scuh edge ..
*/

int main (){
    fast_io
int t;cin>>t;
 while(t--){
 int n;cin>>n;
 vector<ll> a(n);
 for(int i=0;i<n;i++) cin>>a[i];
 
 
bool ok=1; 
vector<ll>b=a;
sort(b.begin(),b.end());

for(int i=1;i<n;i++){
if(b[i]==b[i-1])ok=0;
        }

if(!ok){
cout<<-1<<"\n";
continue;
        }

if(n==1){
 cout<<0<<"\n";
continue;
        }

 sort(a.begin(),a.end());

 vector<ll>sf(n+1);
for(int i=n-1;i>=0;i--)
   sf[i]=(sf[i+1]+a[i])%mod;

ll f=1;
for(int i=1;i<=n-1;i++)
     f=f*i%mod;

 ll ans=0;

 for(int i=0;i<n-1;i++){
  ll cnt=f*pw(n-1-i,mod-2)%mod;

 ll sm=(sf[i+1]-(n-1-i)*(a[i]%mod))%mod;
    sm=(sm+mod)%mod;

    ans=(ans+cnt*sm)%mod;
 }

 cout<<ans<<"\n";
    }


  

return 0;
}