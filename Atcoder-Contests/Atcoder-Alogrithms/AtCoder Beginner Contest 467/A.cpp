
//ABC  467
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/


int main(){
  

      int n;
    cin >> n;

    int l = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        string s;
        cin >> a>> b>> s;

        if (s == "keep") {
        //  l+=(a-b);
            l += (b - a);
        }
    }

    cout << l << endl;
           return 0;
}
