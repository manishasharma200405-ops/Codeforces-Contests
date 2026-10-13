#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main (){
    fast_io

    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;
        if (y <= x) cout << ((x - y) % 2 == 0 ? x : x + 1) << "\n";
        else if (y == x + 1) cout << x + 1 << "\n";
        else cout << -1 << "\n";
    }

    return 0;
}