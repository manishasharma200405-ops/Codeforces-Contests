#include <bits/stdc++.h>
 /*
 Manisha0369
 */
 using namespace std;
 typedef long long ll;
 #define fast_io ios_base:: sync_with_stdio(0);cin.tie(0);
 int main(){
    fast_io;


int n;cin>>n;
vector<ll> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a.begin(),a.end());
ll med=a[n/2];
ll t=0;
for(int i=0;i<n;i++){
    t+=abs(a[i]-med);
}
cout<<t<<"\n";
}