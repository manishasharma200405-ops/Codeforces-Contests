#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast_io;
    int t; cin>>t;
    while(t--){
int n;cin>>n;
int k;cin>>k;
string s;cin>>s;int ans=0;

    if(2*k>n) {
        cout<<-1<<"\n"; 
        continue;
    }


for(int i=0;i<k;i++){
    if(s[i]=='L') ans++;

}
for(int i=n-k;i<n;i++){
    if(s[i]=='R') ans++;
}
cout<<ans<<"\n";
    }

}