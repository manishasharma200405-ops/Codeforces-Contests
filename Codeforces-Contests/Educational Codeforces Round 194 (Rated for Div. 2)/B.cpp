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
      ll x, y, k;
        cin >> x >> y >> k;

 ll d = y - x;
 /*
 whne a >d : d mod a=d since d<a we count X d
 when a<=d : we need mod 
 for  summation of a [d/a ]
 */
 ll lo = x;
 ll hi = x + k - 1;
 ll th = d;

 ll ans = 0;

 ll hh = min(hi, th);
 ll ll1 = lo;
 if (hh >= ll1) {
  ll s = 0;// sum of a*floor of d/a where a in lo and hi rnages 
     ll a = ll1;
     while (a <= hh) {
       ll q = d / a;
      ll a2;
         if (q == 0) {
         a2 = hh;
     } else {
           a2 = d / q;
         if (a2 > hh) a2 = hh;
                }
     ll c = a2 - a + 1;
     ll sm = (a + a2) * c / 2;
     s += q * sm;
       a = a2 + 1;
            }
     ll ms = (hh - ll1 + 1) * d - s;
     ans += ms;
        }
// a is in max l, t+1 where d mdoe a =d direct.
 ll rl = max(lo, th + 1);
 if (hi >= rl) {
       ll c = hi - rl + 1;
   ans += c * d;
        }

        cout << ans << "\n";
    }
    return 0;
}