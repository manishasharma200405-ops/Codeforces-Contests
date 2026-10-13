#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
int main(){
    fast_io
    int n;
    cin>>n;
    vector<ll> s(n),t(n);
    for(auto&x:s)cin>>x;
    for(auto&x:t)cin>>x;
    vector<int> ps(n),pt(n);
    iota(ps.begin(),ps.end(),0);
    iota(pt.begin(),pt.end(),0);
    sort(ps.begin(),ps.end(),[&](int a,int b){return s[a]<s[b];});
    sort(pt.begin(),pt.end(),[&](int a,int b){return t[a]<t[b];});
    vector<int> rs(n),rt(n);
    for(int k=0;k<n;k++){rs[ps[k]]=k;rt[pt[k]]=k;}
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a=s[i]-rs[i];
        ll b=t[i]-rt[i];
        ans+=llabs(a-b);
    }
    vector<int> bit(n+1,0);
    auto add=[&](int i){for(i++;i<=n;i+=i&-i)bit[i]++;};
    auto qry=[&](int i){int r=0;for(i++;i>0;i-=i&-i)r+=bit[i];return r;};
    ll inv=0;
    for(int k=0;k<n;k++){
        int r=rt[ps[k]];
        inv+=k-qry(r);
        add(r);
    }
    ans+=inv;
    cout<<ans<<"\n";
}