#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
int main(){
    fast_io;
    int n;cin>>n;
    vector<ll> l(n);
int t=0;
for(int i=0;i<n;i++){
    cin>>l[i];t+=l[i];
}
int lft=0;
int ans=INT_MAX;
for(int i=0;i<n;i++){
    lft+=l[i];
int rt=t-lft;
ans=min(ans,abs(lft-rt));
}
cout<<ans<<"\n";

}