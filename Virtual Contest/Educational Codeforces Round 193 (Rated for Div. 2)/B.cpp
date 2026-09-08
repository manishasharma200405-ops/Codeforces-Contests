#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

int tt;cin>>tt;
while(tt--){
int n;cin>>n;
vector<ll> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
vector<pair<ll,ll>> b;
for(int i=0;i<n;i++){
    if(b.empty() || b.back().first!=a[i]){
        b.emplace_back(a[i],1);
    }
    else b.back().second++;
}
int m=b.size();
for(int i=0;i<m-1;i++){
    if(b[i].second>1 && b[i+1].second>1){
        cout<<m+2<<"\n";
        goto done;
    }
}
for(int i=0;i<m;i++){
    if(i<m-1 && b[i].second>1 &&(i+2>=m || b[i+2].first!=b[i].first)){
        cout<<m+1<<"\n";
        goto done;
    }
    if(i>0 && b[i].second>1 && (i-2<0 || b[i-2].first!=b[i].first)){
        cout<<m+1<<"\n";
        goto done;
    }
}
cout<<m<<"\n";
done:;



} 
    return 0;
}
