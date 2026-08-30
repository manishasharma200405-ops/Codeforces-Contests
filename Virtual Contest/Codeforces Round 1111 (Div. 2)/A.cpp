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
 int cnt=0;
 for(int i=0;i<n;i++){
  int x;
  cin>>x;
  if(x==-1) cnt++;
 }
 if(n%2==0 &&cnt %2==(n/2)%2){
    cout<<"Yes"<<"\n";
 }else{
    cout<<"No"<<"\n";
 }
 
 
}


  

return 0;
}