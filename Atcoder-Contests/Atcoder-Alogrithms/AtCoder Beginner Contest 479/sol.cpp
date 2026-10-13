#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LIM = 1000000000000000000LL;
ll lcm (ll a, ll b){
    return a/__gcd(a,b)*b;
}
   int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c, n;
    cin >> a >> b >> c >> n;

    ll ab = lcm(a, b);
    ll ac = lcm(a, c);
    ll bc = lcm(b, c);
    ll abc = lcm(ab, c);

    ll lo = 1, hi = LIM;

    if (LIM / ab + LIM / ac + LIM / bc
        - 3 * (LIM / abc) < n) {
        cout << -1 << '\n';
        return 0;
    }

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;

        ll cnt = mid / ab + mid / ac + mid / bc
                 - 3 * (mid / abc);

        if (cnt >= n)
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo << '\n';
}