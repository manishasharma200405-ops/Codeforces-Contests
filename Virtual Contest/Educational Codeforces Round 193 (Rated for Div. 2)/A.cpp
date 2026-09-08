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

int n;cin>>n;
bool ok=true;
for(int i=2;i<=n;i++){
    if((n+1)%i==0){
       ok=false;
       break;
    }
}
cout<<(ok ? "Yes\n" : "No\n");
} 
    return 0;
}