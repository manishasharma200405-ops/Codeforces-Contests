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
vector<int> a(n);
//ai mod ai+1
//note: ai mod ai+1 <ai+1
// ai+2 =ai mod i+1  <a i+1 meaning a2 <=a1
//we need arry in decreaing order so..
for(int i=0;i<n;i++){
    cin>>a[i];

}
sort(a.rbegin(),a.rend());
bool ok=true;
for(int i=0;i<n-2;i++){//for each 1<=i<=n-2 condition is satisfied
 if(a[i+2] !=a[i] % a[i+1]){
    ok=false;
     break;
 }
}
if(ok){
    cout<<a[0]<<" "<<a[1]<<"\n";

}else{
cout<<"-1"<<"\n";
}
} 
    return 0;
}