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
 int n,k,m;cin>>n>>k>>m;
 if(k>m){
    cout<<"No"<<"\n";
continue;
}
cout<<"YES"<<"\n";
for(int i=1;i<=n;i++){
   
   if(i==k){
        cout<<m-k+1<<' ';

    }
    else{
        cout<<1<<' ';
    }
   
}
 cout<<"\n";
}


  

return 0;
}