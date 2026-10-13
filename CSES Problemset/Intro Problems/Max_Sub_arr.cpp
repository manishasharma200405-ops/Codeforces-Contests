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
vector<ll> a(n);//kadane algo 
for(int i=0;i<n;i++){
 cin>>a[i];
}
ll max_sum=a[0];
ll cur=a[0];
for(int i=1;i<n;i++){
    cur=max(a[i],cur+a[i]);
    max_sum=max(max_sum,cur);

}cout<<max_sum<<"\n";
 }