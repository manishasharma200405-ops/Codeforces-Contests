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
       
    int n;cin>>n;
    bool ok=false;
    int m=n+1;
    for(int i=2;i<=n;i++ ){
    if(m%i==0){ok=true;

break;
    }
}
cout<<(ok? "No": "YES")<<"\n";
    
    }
    return 0;
}