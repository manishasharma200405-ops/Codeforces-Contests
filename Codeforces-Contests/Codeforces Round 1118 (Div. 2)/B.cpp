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
vector<int> cnt(m+1,0);
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    cnt[x]++;
}
vector<int> sf(m+2,0);
for(int i=m;i>=1;i--){
    sf[i]=sf[i+1]+cnt[i];
}
int ans=0;
for(int x=1;x<=m;x++){
    int cur=sf[x];
   
    if(2*x<=m){
        cur+=cnt[2*x];
    }


    
    ans=max(ans,cur);
}
cout<<ans<<"\n";

 }




  

return 0;
}