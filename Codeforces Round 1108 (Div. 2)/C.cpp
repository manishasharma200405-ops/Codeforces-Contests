
//Div 2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/

typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,b) for(int i=0;i<=b;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
const int MOD= 1e9+7;
vector<ll> w;
void prep(int m){
w.assign(m+1,1);
fori(i,1,m+1) w[i]=(w[i-1]*2)%MOD;
}

int main(){
    
prep(200000);
    int tt; cin >> tt;
    while(tt--){
        int n;cin>>n;
    vector<ll> ap(n+1);
    rep1(i,1,n) cin>>ap[i];
        
    vector<ll> vol;
    vector<int> ct;
    int i=1;
    while(i<=n){
        int j=i;
        while(j<=n && ap[j]==ap[i]) j++;
vol.pb(ap[i]);
ct.pb(j-i);
i=j;

    }
    int d=(int )vol.size();
    int lep=0;
    fori(k,0,d-1){
if(vol[k]>=1 && vol[k+1] == vol[k]+1 ) lep++;

    }
    //ll nes=w[d-k];
    //if (vol.empty() || vol[0]==1){;}
    ll nes=w[n-d];
    if(!vol.empty() && vol[0] ==-1){
        nes=nes*((lep+1) %MOD ) %MOD;
    }
    cout<<nes<<"\n";
   
        }    return 0;
}
