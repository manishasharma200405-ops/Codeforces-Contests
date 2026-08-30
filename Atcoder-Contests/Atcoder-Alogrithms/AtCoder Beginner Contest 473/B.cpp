#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast_io;
    int n;cin>>n;
    vector<int > cnt(101,0);
    for(int i=0;i<n;i++){
       int x ; cin>>x;
       cnt[x]++;
    }
    int ans=0;
    for(int i=1;i<=100;i++){
        if(cnt[i]%2==1){
            ans+=i;
        }
    }
cout<<ans<<"\n";
return 0;

}