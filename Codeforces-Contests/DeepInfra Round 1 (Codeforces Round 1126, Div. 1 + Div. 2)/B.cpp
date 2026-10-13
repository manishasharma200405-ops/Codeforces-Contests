#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main (){
    fast_io

    int t;
    cin>>t;

    while(t--){
       int n,k;
        cin>>n>>k;
        vector<int> cnt(n+2,0);
        for (int i=0;i<n;i++) {
            int a;
            cin>>a;
            cnt[a]++;
        }
        bool win=false;
        for (int v=0;v<=n+1;v++) {
            if (cnt[v]<2*k) {
                win =(cnt[v]==2*k-1);
                break;
            }
        }
        cout<<(win?"YES":"NO")<<"\n";
    }

    return 0;
}