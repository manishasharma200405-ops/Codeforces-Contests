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
    int a,b,c;cin>>a>>b>>c;
 
    //sort the numbers
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
   int ans =c-a;
   if(c>=a+b){
    ans=min(ans,b);
   }
   cout<<ans<<"\n";
}
    
    return 0;
}