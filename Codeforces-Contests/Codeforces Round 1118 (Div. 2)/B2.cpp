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
 for(int  i=0;i<n;i++){
    int x;cin>>x;
    cnt[x]++;
 }
 vector<int> pf(m+1,0);
 for(int i=1;i<=m;i++){
    pf[i]=pf[i-1]+cnt[i];
 }
 vector<long long > ans;
 long long pw=2;
 while(true){
    long long b=0;


    for(int x=1;x<=m;x++){
        long long cur=0;
        for(int q=1;q*x<=m;q++){
            int l=q*x;
            int r=min(m,(q+1)*x-1);
            int amt=pf[r]-pf[l-1];
            cur+=1LL*min<long long >(q,pw)*amt;

        }
        b=max(b,cur);
    }
    ans.push_back(b);
    if(pw>= m) break;
    pw*=2;

 }
 for(int k=1;k<=m;k++){
    int id=min(k-1,(int)ans.size()-1);
    cout<<ans[id]<<" ";
 }
 cout<<"\n";
}


  

return 0;
}