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
       int n;
        cin>>n;
        int s=1;
        while(s<=n)s*=2;
        int h=s/2;
        vector<int>p;
        p.reserve(2*s);
        for(int v=0;v<h;v++){
            p.push_back(v);
            p.push_back(v);
        }
        for(int v=s-1;v>=h;v--){
            p.push_back(v);
            p.push_back(v);
        }
        int m=2*s-1;
        cout<<m<<"\n";
        for(int i=1;i<=m;i++){
            cout<<(p[i]^p[i-1])<<" \n"[i==m];
        }
    }

    return 0;
}