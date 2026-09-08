#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll ;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

     int n,q;cin>>n>>q;
    string s;cin>>s;
    vector<ll> z(n+1),o(n+1),d(n+1);
for(int i=1;i<=n;i++){
        z[i]=z[i-1]+(s[i-1]=='0');
        o[i]=o[i-1]+(s[i-1]=='1');
    }
/*
increasing k beyond r costs 1 exact extra insertion we need to make sure each pair is equal 
k = max(ceil(c0/2), upper vals ....
ceil(c1/2), ...
ceil((c0+c1-R)/3), R)...
*/

    for(int i=1;i<n;i++) d[i]=d[i-1]+(s[i-1]!=s[i]);
    while(q--){

        int l,r;cin>>l>>r;
        ll a=z[r]-z[l-1];
        ll b=o[r]-o[l-1];


        ll lin=d[r-1]-d[l-1];


        ll t=lin+(s[l-1]!=s[r-1]);
        ll R=t/2;


        ll k1=(a+1)/2;


        ll k2=(b+1)/2;


        ll k3=(a+b-R+2)/3;

        ll k=max({k1,k2,k3,R});
        cout<<(4*k-a-b)<<"\n";
    
    }
    return 0;
}