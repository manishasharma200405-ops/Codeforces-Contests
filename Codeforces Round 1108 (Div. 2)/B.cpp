
//Div 2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/

typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
int main(){
    

    int tt; cin >> tt;
    while(tt--){
        int n;cin>>n;
           if(n==2) {cout<<"-1"<<"\n";continue ;}
    vector<ll> an;
    an.pb(1);
    if(n>=3){
        an.pb(2); an.pb(3);
    }
    ll sum=0;
    for(ll c:an){
        sum+=c;
    }
    rep1(k,4,n){
        an.pb(sum);
        sum*=2;
    }
    fori(i,0,(int)an.size()){
        //if(i==(int)an.size()-1){}
        cout<<an[i]<<" \n"[i==(int)an.size()-1];
    }
        }    return 0;
}
