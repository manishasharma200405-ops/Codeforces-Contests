//div2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - 
*/
typedef long long ll;

//#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,b) for(int i=0; i<=(b); i++)
#define rep1(i,a,b) for(int i=(a); i<=(b); i++)
int main(){
int tt;
 cin >> tt;
//prefix sum used 
    while(tt--){
        int n, k;
        ll m;
        cin >> n >> k >> m;

        if(k > m){ cout << "NO\n";continue; }

        cout << "YES\n";

        vector<ll> pr(n + 1);

        rep(i, n){//pr[i]=i*k;
            pr[i] = i % k;
        }

        rep1(i, 1, n){
            // int x=(pr[i]-pr[i+]+m);
            ll x = (pr[i]-pr[i-1]+m)%m;
            if(x == 0) x = m;
            cout << x << " ";
        }
        cout << "\n";
    }

    

    return 0;
}