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
 if(n==1) {cout<<"1\n";continue;}
 if(n==2) {cout<<"-1\n"; continue ;}
 cout<<"1 2 ";
 long long  c=3;
for(int i=2;i<n;i++){
  cout<<c<<" ";
  c*=2;
}
 
cout<<"\n";
  
}
return 0;
}