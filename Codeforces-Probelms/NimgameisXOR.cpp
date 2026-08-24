#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll; 
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
int t;cin>>t;
while(t--){
  int n;cin>>n;
  vector<int > a(n);
  int x=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    x^=a[i];

  }if(x==0){
    cout<<"1"<<"\n";
  }else{
  if(n==1){
    cout<<"0"<<"\n";

  }else{
    int ans=0;
    for(int i=0;i<n;i++){
        if((x^a[i])< a[i]){ ans+=1;}

    }
  
  cout<<ans<<"\n";
}
}
} 
    return 0;
}