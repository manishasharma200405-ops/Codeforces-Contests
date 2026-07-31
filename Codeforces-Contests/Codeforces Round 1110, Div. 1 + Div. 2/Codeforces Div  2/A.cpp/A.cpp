// //Div 2
// #include <bits/stdc++.h>
// using namespace std;

// /*
// Author - Kenway-Connor
// */

// #define ll long long
// #define rep(i,n) for(int i=0;i<n;i++)
// #define rep1(i,a,b) for(int i=a;i<=b;i++)

// int main() {

//     int tt;
//     cin >> tt;

//     while (tt--) {

//         ll n, m;
//         cin >> n >> m;

//         ll ans = 0;

//         rep(i, 30) {
//             ll p = 1LL << i;      
//             ll num = min(n / p, m);
//             ans += num;
//             n -= num * p;
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }
//Div 2
#include <bits/stdc++.h>
using namespace std;

/*
Author - Connor_Kenway
*/

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)

int main() {

    int tt = 1;

    while (tt--) {

        int m, d;
        cin >> m >> d;

        string s;
        cin >> s;

        vector<bool> w(m, false);

        rep(i, m) {
            if (s[i] == 'G') {
                int l = max(0, i - d);
                int r = min(m - 1, i + d);

                rep1(j, l, r)
                    w[j] = true;
            }
        }

        int ans = 0;
        rep(i, m) {
            if (!w[i]) ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}