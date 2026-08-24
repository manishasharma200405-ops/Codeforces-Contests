#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int fnd(vector<int>& p, int x){
    while(p[x] != x) x = p[x] = p[p[x]];
    return x;
}

int main() {
    fast_io
    int t; cin >> t;
    while (t--) {
   

    }
}