#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void slv(){//upsolve

//in main 
}


int main (){
    fast_io
int t;cin>>t;
 while(t--){

int n;cin>>n;
vector<int > a(n),b(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    cin>>b[i];
}
sort(a.begin(),a.end());
sort(b.begin(),b.end());

if(a==b){
cout<<"Yes"<<"\n";
continue;
}
  int x=0;
  
  for(auto it :a) x^=it;
  for(auto it :b) x^=it;
  int idx=-1;
  for(int i=0;i<n;i++){
    if(a[i]==x){
        idx=i;
        break;
    }
  }
  if(idx==-1){
    cout<<"No"<<"\n";
    continue;
  }
  for(int i=0;i<n;i++){
    if(i==idx)continue;
    a[i]^=x;

  }
  sort(a.begin(),a.end());
  cout<<(a==b ? "Yes":"No")<<"\n";

 }
return 0;
}