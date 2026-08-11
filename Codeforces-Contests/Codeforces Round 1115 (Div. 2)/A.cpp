#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> cnt(1001);
        int sum = 0;
// if all are distinct
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            cnt[x]++;
        }

        for (int x = 1; x <= 1000; x++)
            if (cnt[x] > (n + 2) / 2)
                sum -= (2 * cnt[x] - n - 2) * x;

        cout << sum << '\n';
    }
    return 0;
}