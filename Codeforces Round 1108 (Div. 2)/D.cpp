//Div 2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
#define rep(i,b) for(ll i=0;i<b;++i)
#define rep1(i,a,b) for(int i=a;i<=b;i++)

const int MAV = (1<<18)+5;
int fin[MAV];

void prep(){
    fin[0]=0;
    rep1(z,1,MAV-1){
        if(z & 1) fin[z] = fin[z-1] + 1;
        else      fin[z] = fin[z>>1] + 1;
    }
}

int fonk(int z){
    return fin[z];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   prep();

    int tt; cin >> tt;
    while(tt--){
     int n;cin>>n;
     vector<int> an(n);
     rep(i,n) cin>>an[i];
     ll lest= LLONG_MAX;
     
     rep1(k,0,17){
        ll on=1LL <<k;
        ll sun=0;
        rep(i,n){
            ll x=an[i];
    
            ll di=((x+on-1)/on)*on;
//ll v=d/on;
            ll v0=di/on;
            ll noc=LLONG_MAX;
            rep1(p,0,17){
                //int w =1LL^p;
                ll w=1LL<<p;
                ll v=((v0+w-1)/w)*w;
                ll b=v*on;
                ll toss=(b-x)+fonk((int)v);
                noc=min(noc,toss);
            }
             sun+=noc;
        }
        lest=min(lest,(ll)k+sun);
     }
     cout<<lest<<"\n";
   
        }    return 0;
}
