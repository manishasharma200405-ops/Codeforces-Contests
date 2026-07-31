
//Div 3 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()


int main(){
    

    int tt; cin >> tt;
    while(tt--){
        int n;
        cin >> n;

        vector<ll> a(n);
         fori(i,0,n) cin >> a[i];

        ll nd = 1;
        bool k = 1;

        fori(i,0,n-1) {
            if (a[i] < nd) {
                k = 0;
                break;
            }
            a[i+1] += a[i] - nd;
            nd++;
        }

        cout << (k && a[n-1] >= nd ? "YES" : "NO") << '\n';
    
        }    return 0;
}
