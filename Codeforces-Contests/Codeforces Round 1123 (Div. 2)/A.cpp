#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
       int n;cin>>n;
     char c;cin>>c;
       string s ;cin>>s;
       int ans=0;
       for(int i=0;i<n/2;i++){
        if(s[i]==s[n-1-i])
            continue;
        if(s[i]==c || s[n-1-i]==c){
            ans++;
        }
        else ans+=2;

       }
       cout<<ans<<"\n";
   
    
    }
    return 0;
}