#include <bits/stdc++.h>
/*
  Player__
*/
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll ;
vector<ll> get(vector<ll>&a,ll k){
    if(k<a.size()) return vector<ll>(a.end()-k,a.end());
    return a;
}

void solve(){
    ll n,m,x,y;
    cin>>n>>m>>x>>y;

    vector<ll>a(x),b(y);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;

    vector<ll>c,one,two;
    ll i=0,j=0;

    while(i<x&&j<y){
        if(a[i]==b[j]){
            c.push_back(a[i]);
            i++,j++;
        }
        else if(a[i]<b[j]){
            one.push_back(a[i++]);
        }
        else two.push_back(b[j++]);
    }

    while(i<x) one.push_back(a[i++]);
    while(j<y) two.push_back(b[j++]);

    vector<ll>res=get(one,n);
    vector<ll>tmp=get(two,m);

    res.insert(res.end(),tmp.begin(),tmp.end());
    res.insert(res.end(),c.begin(),c.end());

    sort(res.begin(),res.end());
    res=get(res,n+m-1);

    cout<<accumulate(res.begin(),res.end(),0LL)<<'\n';
}
int main(){
    fast_io;
  int tt;cin>>tt;
  while(tt--){
       slv();}
      

}