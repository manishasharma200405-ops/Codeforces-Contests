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
 int x=0;
 for(int i=0;i<n;i++){
    //rem pair of 0 nad 1 
    int a;cin>>a;
    x+=a;
 }
 if(x>=(n+1)/2) cout<<"Bessie\n";
 else cout<<"Elsie\n";
 

}


  

return 0;
}