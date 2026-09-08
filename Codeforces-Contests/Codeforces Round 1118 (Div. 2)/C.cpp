#include <bits/stdc++.h>
using namespace std;

/*
Author - Player__
*/

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast_io

    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;

        auto ask=[&](int u,int v,int d){
            cout<<"? "<<u+1<<' '<<v+1<<' '<<d<<endl;
            int x;cin>>x;
            return x;
        };

        int v=0,d=0;
        for(int i=1;i<n&&d!=n-1;i++){
            if(!ask(0,i,d+1))continue;
            v=i;
            d++;
            while(d!=n-1&&ask(0,i,d+1))d++;
        }

        int u=0;
        for(int i=0;i<n&&d!=n-1;i++){
            if(i==v)continue;
            if(!ask(v,i,d+1))continue;
            u=i;
            d++;
            while(d!=n-1&&ask(v,i,d+1))d++;
        }

        cout<<"! "<<u+1<<' '<<v+1<<' '<<d<<endl;
    }

    return 0;
}