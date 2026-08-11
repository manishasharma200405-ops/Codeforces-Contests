#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
int t;cin>>t;
 while(t--){
 int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int ae = 0, ao = 0;//substring count
        int be = 0, bo = 0;//choose substring-->

        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                if (i % 2 == 0) ae++;
                else ao++;
            }
            if (b[i] == '1') {
                if (i % 2 == 0) be++;
                else bo++;
            }
        }

        if (ae == be && ao == bo)
            cout << "YES\n";
        else
            cout << "NO\n";


 }

  

return 0;
}