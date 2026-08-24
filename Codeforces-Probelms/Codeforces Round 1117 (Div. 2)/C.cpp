#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll; 
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main (){
    fast_io
int t;cin>>t;

while(t--){
  int n;cin>>n;
  vector<int> par(n+1);
  for(int i=2;i<=n;i++){
    cin>>par[i];

  }
  int m;cin>>m;
  vector<int > a(m);
  vector<bool> dm(n+1,false);
  for(int &x:a){
    cin>>x;
    dm[x]=true;

  }
  vector<int> ans;
  int sp=(dm[1] ?1:a[0]);
  for(int x:a){
    if(x==sp){
        continue;
    }
    ans.push_back(x);
  }
  cout<<ans.size();
     
  for(int x:ans){
    cout<<' '<<x;
  }
  cout<<"\n";
    }

    return 0;
}