#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
    int n;
    string s;
    cin >> n >> s;
    int cur = 0, best = 0;
    for(char c : s){
        if(c == 'R'){
            cur++;
            best = max(best, cur);
        }
        else cur = 0;
    }
    cout << best << "\n";
    return 0;
}