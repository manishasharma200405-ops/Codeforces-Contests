
//ABC 467 
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
    int tt;
    cin >> tt;

    while (tt--) {
        ll px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

        ll ax = qx - px;
        ll ay = qy - py;
        ll bx = sx - rx;
        ll by = sy - ry;
        // ll c=ax* bx - ay*by;
        ll c = ax*by - ay*bx;

        if (c != 0) {
            cout << "Yes\n";
            continue;
        }

        ll mx = px + qx;
        ll my = py + qy;
        ll nx = rx + sx;
        ll ny = ry + sy;

        ll dx = mx - nx;
        ll dy = my - ny;

        if (dx*ax + dy*ay == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    
       

    return 0;
}
