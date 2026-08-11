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

        
 vector<int> ae, ao, be, bo;

        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                if (i % 2 == 0) ae.push_back(i);
                else ao.push_back(i);
            }

            if (b[i] == '1') {
                if (i % 2 == 0) be.push_back(i);
                else bo.push_back(i);
            }
        }

        if (ae.size() != be.size() || ao.size() != bo.size()) {
            cout << -1 << "\n";
            continue;
        }

        long long ans = 0;
//we store the position of 1 in odd and even indices
        for (int i = 0; i < (int)ae.size(); i++)
            ans += abs(ae[i] - be[i]) / 2;

        for (int i = 0; i < (int)ao.size(); i++)
            ans += abs(ao[i] - bo[i]) / 2;

        cout << ans << "\n";

 }

  

return 0;
}