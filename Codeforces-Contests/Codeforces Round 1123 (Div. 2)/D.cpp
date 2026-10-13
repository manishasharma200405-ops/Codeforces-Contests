#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
       int n;cin>>n;
       vector<int> a(n+1,0);
       for(int i=1;i<=n;i++){int x;cin>>x;
        a[x]=i;
       }

     //a parity prob
     vector<char> pos(n+1,0);
     for(int i=1;i<=n;i++){
        pos[i]=(a[i] %2==1);
     }
     bool pl=true;
     bool pr =(n%2==1);
     bool ok = true;
     for(int i=1;i<=n;i++){
        bool nd=pos[i];
        if(pl==pr){
            if(pl!=nd){
            ok=false;break;
                   
            }
        
        bool n1=!nd;
        bool n2=nd;
        pl=n1;pr=n2;

     }else {
        bool val =!nd;
        pl=val; pr=val;
     }}
    cout<<(ok ? "Yes": "No")<<"\n";
    }
    return 0;
}