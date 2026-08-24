#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
int t;cin>>t;
 while(t--){
int n;cin>>n;
vector<ll> b(n);
map<ll,ll> fre;
for(int i=0;i<n;i++){
    cin>>b[i];fre[b[i]]++;
}
if(!fre.count(0)){
    cout<<-1<<endl;continue;
}
map<ll,ll> an;
ll prv=0,cnt=0,lst=0;
bool ok=true;
for(auto[cur,cur_cnt]:fre){
    if(cur!=0){
        ll dif=cur-prv;
    
    if(dif%cnt!=0){
        ok=false;
        break;
    }
    ll u=dif/cnt;
    if(u<=lst){
        ok=false;
        break;
    }
    an[prv]=u;
    lst=u;
    }
prv=cur;
cnt=cur_cnt;
}
 




 if(!ok){
    cout<<-1<<endl;continue;
 }
 an[prv]=lst+1;
for(int i=0;i<n;++i) cout<<an[b[i]]<<" \n"[i==n-1];
  
 }
return 0;
}