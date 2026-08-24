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

int n;cin>>n;
string s ;cin>>s;int ans=1;
for(int i=1;i<n;i++){
    
    if(s[i]!=s[i-1])
       ans++;
}
int f=ans;
for(int i=1;i<n-1;i++){
    if(s[i-1]==s[i+1]&& s[i]!=s[i-1]){
        f=min(f,ans-2);
    }
    else if(s[i]!= s[i-1] && s[i]!=s[i+1]){
        f=min(f,ans-1);
    }

}
cout<<f<<"\n";

}


  

return 0;
}