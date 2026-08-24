#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void slv(){
    int n;cin>>n;
multiset<ll > b;//we insert elements in b into mulitset
for(int i=0;i<n;i++){
    ll c;cin>>c;
    b.insert(c);
}
vector<ll> ans(n);ll cur=0;//query multiset for lb of 1-a
for(int i=0;i<n;i++){
    auto it=b.lower_bound(1-cur);
    if(it==b.end()) return void (cout<<-1<<'\n');
    cur+=*it;
    b.erase(it);
    ans[i]=cur;
}
for(int i=0;i<n;i++){
    cout<<ans[i]<<" \n"[i==n-1];
}
// editorial solve
//upsolve

 
}


int main (){
    fast_io
int t;cin>>t;
 while(t--){
slv();
 }
return 0;
}