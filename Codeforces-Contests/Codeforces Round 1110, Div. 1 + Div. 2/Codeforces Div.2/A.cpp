//div2 
#include <bits/stdc++.h>
using namespace std;

//typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
//#define pb push_back
int main(){
int tt;
 cin >> tt;
//zero sum 
    while(tt--){
        int n;
        cin >> n;
        int cnt = 0;
        rep(i,n){
          int x; cin >> x;if(x == 1) cnt++;
        }

        if(n % 2 == 1){ cout << "NO\n";}
       
        else if((cnt% 2) == ((n / 2) % 2)){ cout << "YES\n";}
        else{ cout<< "NO\n";}
    }

    return 0;
}