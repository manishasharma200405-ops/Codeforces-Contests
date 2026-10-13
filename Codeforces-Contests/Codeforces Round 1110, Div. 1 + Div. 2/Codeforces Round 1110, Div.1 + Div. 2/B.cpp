
//Div 3 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)



int main(){
    

    int tt; cin >> tt;
    while(tt--){
        int n;cin>>n;ll c;cin>>c;
        vector<ll > an(n);
       
        ll sun=0;
        rep(i,n){
            cin>>an[i]; sun+=an[i];
        }
        vector<ll> bn(n);
        rep(i,n){
            bn[i]=c-an[i];
        }
        sort(bn.rbegin(),bn.rend());
        int mus=n/2;
        ll lest=0;ll run=0;
        rep(i,mus){
            if(bn[i]<0) break;
            run+=bn[i];
            lest=max(lest,run);
            
            
        }
        ll res=sun-c*1LL *n+lest;
        cout<<res<<"\n";

        }    return 0;
}
