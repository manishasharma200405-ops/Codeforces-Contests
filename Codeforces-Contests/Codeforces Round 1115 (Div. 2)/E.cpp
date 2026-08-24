#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const int MOD=1000000007;
ll dp[65][2][2][2];
ll n;
ll slv(int bit,int cless,int aless,int nd){
    if(bit<0){
        if(nd==0 && aless==1) return 1;
        return 0;
    }
    if(dp[bit][cless][aless][nd]!= -1){
        return dp[bit][cless][aless][nd];
    }
    ll ans=0;
    int nbit=(n >>bit) &1;
    for(int i=0;i<=1;i++){
        for(int c=0;c<=1;c++){
            if(cless && c >nbit) continue;
            if(!aless && i> c) continue;

            if(nd==1 && (i & c)==0) continue;
            if(nd ==0 && (i &c)==1) continue;

            int nxtc=cless && (c==nbit);
            int nxta=aless || (i < c);
            int nxtneed=i ^ c;

            ans=(ans+slv(bit -1,nxtc, nxta,nxtneed)) % MOD;
        }
    }
    return dp[bit][cless][aless][nd]=ans;
}
void think(){
cin>>n;
memset(dp,-1,sizeof(dp));
cout<<slv(60,1,0,0)<<"\n";
}
//upsolving with edits
int main(){
    fast_io
    int t; cin>>t;
    while(t--){
    think();
    }
    return 0;
}