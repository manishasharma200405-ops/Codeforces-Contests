
//Div 2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/

typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,b) for(int i=0;i<=b;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
//#define pb push_back


int main(){
    
 int n, m;
    cin >> n >> m;

    vector<int> a(n+1), b(n), f(n+1);

    rep1(i,1,n) cin>>a[i];
    rep1(i,1,n-1) cin>>b[i];

    int x = 2e9;

    rep(s, 1) {
        fill(f.begin(), f.end(), 0);
        f[1] = s;

        rep1(i, 1, n - 1) {
            //f[i+1]=f[i] ^ a[i];
            f[i+1]=f[i] ^ b[i];
            f[i+1] ^= (a[i]&1) ^(a[i + 1]&1);
        }

        int c = 0;
        rep1(i,1,n) c+=f[i];

        x = min(x,c);
    }

    cout <<x<<'\n';

    return 0;
}
