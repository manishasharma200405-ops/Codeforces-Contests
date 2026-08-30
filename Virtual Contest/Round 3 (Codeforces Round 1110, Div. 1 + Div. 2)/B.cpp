#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
int main(){
    fast_io;
 int tt;cin>>tt;
 while(tt--){
    int n;cin>>n;
ll c ;cin>>c;
vector<ll> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a.begin(),a.end());
for(int i=0;i<n;i++){
    a[i]-=c;
}
for(int i=0;i<n/2;i++){
    a[i]=max(a[i],0LL);

} 
ll ans =0;
for(int i=0;i<n;i++){
    ans+=a[i];
}
cout<<ans<<"\n";
 }return 0;

}