
//Div 3 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/



int main(){
    

    int tt; cin >> tt;
    while(tt--){
       
 int n; cin >> n;
        string s; cin >> s;

        int ans = 0, cn = 0;
        for (char c : s)
            if (c == '#')
                nes = max(nes, ++cn);
            else
                cn = 0;

        cout << (nes + 1) / 2 << '\n';
    }
    return 0;
}
