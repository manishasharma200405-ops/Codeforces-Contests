#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
pair<ll,ll> solve(vector<ll>&a,vector<ll>&b){
    int n=a.size();
    vector<array<ll,3>> v;
    ll cons=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)cons+=llabs(b[i]);
        else{
            ll sg=a[i]>0?1:-1;
            v.push_back({b[i]*sg,llabs(a[i]),llabs(a[i])});
        }
    }
    if(v.empty())return {cons,1};
    sort(v.begin(),v.end(),[&](const array<ll,3>&x,const array<ll,3>&y){return x[0]*y[1]<y[0]*x[1];});
    ll w=0;
    for(auto&x:v)w+=x[2];
    ll cum=0,p=0,q=1;
    for(auto&x:v){
        cum+=x[2];
        if(2*cum>=w){
            p=x[0];
            q=x[1];
            break;
        }
    }
    if(p>q){p=1;q=1;}
    if(p<-q){p=-1;q=1;}
    ll num=0;
    for(int i=0;i<n;i++)num+=llabs(b[i]*q-p*a[i]);
    return {num,q};
}
int main(){
    fast_io
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    auto r1=solve(a,b);
    auto r2=solve(b,a);
    pair<ll,ll> r=r1;
    if((__int128)r2.first*r1.second<(__int128)r1.first*r2.second)r=r2;
    ll g=__gcd(r.first,r.second);
    cout<<r.first/g<<" "<<r.second/g<<"\n";
    return 0;
}