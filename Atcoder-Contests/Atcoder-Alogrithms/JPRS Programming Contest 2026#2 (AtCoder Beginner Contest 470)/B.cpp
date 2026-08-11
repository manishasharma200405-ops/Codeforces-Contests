#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

 int n;cin>>n;
     
    vector<int > a(n);
    vector<int> freq(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        freq[a[i]]++;    }
    int mx=0;
    
  for(int i=1;i<=n;i++){
    mx=max(mx,freq[i]);
  }
cout<<(n-mx)<<"\n";
return 0;
}