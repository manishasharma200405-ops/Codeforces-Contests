#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
       int n,k;cin>>n>>k;

  int ans =2*(k-1)+(1<< (n-k+1));
  cout<<ans<<"\n";
      
    }
    return 0;
}