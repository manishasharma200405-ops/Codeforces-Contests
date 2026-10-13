
//Div 3 
#include <bits/stdc++.h>
using namespace std;


 #define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)


int main(){
    

    int tt; cin >> tt;
    while(tt--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        if(2*k >n) {cout<<-1<<"\n";continue;}
      // int nas= INT_MAX;
   
   


      int c = 0;
    rep(i, k) if(s[i] != 'R') c++;         
    rep1(i, n-k, n-1) if(s[i] != 'L') c++; 

    cout << c << "\n";
        }    return 0;
}
