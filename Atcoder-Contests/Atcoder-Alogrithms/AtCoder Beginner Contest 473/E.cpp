#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast_io;
    
 int n;cin>>n;
 long long k;cin>>k;
 set<long long > sn;
 sn.insert(0);
 long long sum=0;
 int ans=0;
for(int i=0;i<n;i++){
    long long x;cin>>x;
    sum=(sum+x)%k;
    if(sn.count(sum)){
        ans++;
        sn.clear();
        sn.insert(0);
        sum=0;
    }else{
        sn.insert(sum);
    }
}
cout<<ans<<"\n";
return 0;


}