#include <bits/stdc++.h>
using namespace std;
/*
Author - Player007
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
int tt;cin>>tt;
while(tt--){
   int n;cin>>n;
  
  
 for(int i=1;i<=n;i+=2){
    cout<<(i+1)<<" "<<i<<" ";
 }
 cout<<"\n";

}
return 0;
}