
//Div 2  Educational 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/

 #define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)


int main(){
    

    int tt; cin >> tt;
    while(tt--){
     int k;cin>>k;
     vector<int> c(k);
     int val = 0;
        int cnt = 0;

        rep(i,k){ 
            cin>>c[i];
            if(c[i] > val) {
                val = c[i];
            }
            if(c[i] == 2) {
                cnt++;
            }
        }
    
        if(val > 2 || cnt > 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    
        }    return 0;
}
