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
       vector<int> a(n);
       int frq[101]={0};
       for(int i=0;i<n;i++){
        cin>>a[i];
        frq[a[i]]++;
       }
       int mx=0;
       for(int i=1;i<=100;i++) mx=max(mx,frq[i]);
       vector<int> res;
       res.reserve(n);
       for(int i=1;i<=mx;i++){
        for(int j=100;j>=1;j--){
            if(frq[j]>=i) res.push_back(j);
        }
       }
       for(int i=0;i<(int)res.size();i++){
       cout<<res[i]<<" \n"[i+1==(int)res.size()];
     

       }
    
    }
    return 0;
}