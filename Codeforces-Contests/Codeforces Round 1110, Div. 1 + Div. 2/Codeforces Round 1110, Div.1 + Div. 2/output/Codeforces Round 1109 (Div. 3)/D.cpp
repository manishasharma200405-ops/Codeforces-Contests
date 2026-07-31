
//Div 3 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
 const ll NEG = LLONG_MIN/2;
int main(){
    

    int tt; cin >> tt;
    while(tt--){
       int n,m;
    cin>>n>>m;
    vector<ll> a(n+1);
    rep1(i,1,n) cin>>a[i];
    
    vector<ll> pr(n+1,0);

    rep1(i,1,n) pr[i]=pr[i-1]+a[i];
    vector<int> b(m);
    rep(i,m) cin>>b[i];

    sort(b.rbegin(), b.rend());
    ll bas = pr[n]-pr[b[0]];
   //int bs= pr[n+1] - pr[b];
    ll dp=0, dp1=NEG;
    rep(k,m){
        int cun=b[k];
        int nxt=(k+1<m) ?  b[k+1] : 0;
        //int kt =(k+1) ? pr[k+1] :0;

        ll s=pr[cun]-pr[nxt];
        //ll u=pr[cur]- pr [0];
        ll np=max(dp,dp1)+s;

        ll np1=max(dp1,dp)-s;
        dp=np; dp1=np1;
    }
    cout<<bas+max(dp,dp1)<<"\n";
      

          
    
        }    return 0;
}
