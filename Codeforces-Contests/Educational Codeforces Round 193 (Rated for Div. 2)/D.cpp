#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

   int n,q;
    cin>>n>>q;

    vector<int> p(n+1), inv(n+1);

    for(int i=1;i<=n;i++){
        cin>>p[i];
        inv[p[i]]=i;
    }

    while(q--){
        int t;
        cin>>t;

        if(t==1){
            int x,y;
            cin>>x>>y;

            int a=p[x], b=p[y];

            swap(p[x],p[y]);
            inv[a]=y;
            inv[b]=x;
        }
        else{
            swap(p,inv);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<p[i]<<" ";
    }

    cout<<"\n";
    return 0;
}