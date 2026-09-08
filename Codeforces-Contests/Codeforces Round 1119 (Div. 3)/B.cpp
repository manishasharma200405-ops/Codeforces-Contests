#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

int tt;cin>>tt;
while(tt--){
int n;cin>>n;
int odd=0,z=0,two=0;
for(int i=0;i<n;i++){
  ll x;cin>>x;
  if(x%2) odd++;
  else if(x%4==0) z++;
  else two++; 
}
cout<<max({odd,z,two})<<"\n";

} 
    return 0;
}