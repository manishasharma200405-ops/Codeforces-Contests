#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
int t;cin>>t;
 while(t--){
 
 

int n,m;cin>>n>>m;
 vector<ll>a(n);
 for(int i=0;i<n;i++)cin>>a[i];

 priority_queue<ll> q;
 ll s=0,ans=LLONG_MIN;

for(int i=0;i<n;i++){
     if(q.size()==m-1){
 ans=max(ans,1LL*m*a[i]-s);
            }

q.push(a[i]);
s+=a[i];

if(q.size()>m-1){
  s-=q.top();
 q.pop();
            }
        }

  cout<<ans<<"\n";
    }

/*
we wanted a[i ] to be large so i did as i multipyl by m . 
m-1 to be smallest pos . sum .....*/
  

return 0;
}