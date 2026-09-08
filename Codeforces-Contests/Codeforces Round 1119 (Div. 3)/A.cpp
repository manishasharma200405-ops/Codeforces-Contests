#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

int tt;cin>>tt;
while(tt--){
int n,k;cin>>n>>k;
string s;cin>>s;
int ans=0;
for(int i=0;i<n;i+=k){
    bool ok=true;
    for(int j=i;j<i+k;j++)
{
    if(s[j]=='0'){
        ok=false;
        break;
    }
}
if(ok) ans++;
}
cout<<ans<<"\n";
} 
    return 0;
}