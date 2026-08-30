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
    vector<long long> a(n);

//2k+1
//first and last remain always
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<__gcd(a[0],a[n-1])<<"\n";
}


  

return 0;
}