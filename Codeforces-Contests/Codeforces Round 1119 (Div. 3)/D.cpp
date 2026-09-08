#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast_io

    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vector<ll>a(n);
        vector<vector<int>>p(n+1);
        vector<int>c(n+1);//dumping 

        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<=n){
                c[a[i]]++;
                p[a[i]].push_back(i);
            }
        }

        int x=0,y=0,z=0;
        while(x<=n&&c[x]) x++;
        while(y<=n&&c[y]>=2) y++;
        while(z<=n&&c[z]>=3) z++;

        if(x==0){
            cout<<"YES\n";
            for(int i=0;i<n;i++) cout<<"A";
            cout<<"\n";
            continue;
        }

        int m=min(x,y+z);

        if(m==0){
            cout<<"NO\n";
            continue;
        }

        int a1=z;
        int a2=min(y,m);
        int a3=m;

        if(a1+a2<a3){
            cout<<"NO\n";
            continue;
        }

        vector<char>ans(n,'A');
        vector<int>mx={a1,a2,a3};

        for(int v=0;v<=n;v++){
            if(p[v].empty()) continue;

            vector<int>hi,lo;

            for(int j=0;j<3;j++){
                if(mx[j]>v) hi.push_back(j);
                if(mx[j]<v) lo.push_back(j);
            }

            if(p[v].size()<hi.size()){
                cout<<"NO\n";
                goto done;
            }

            int q=0;

            for(int j:hi){
                ans[p[v][q]]="ABC"[j];
                q++;
            }
//copyingone to every grp ... whose mex >v
///thne i put the rmeian to somehwere safe ....
            int to;
            if(!lo.empty()) to=lo[0];
            else if(!hi.empty()) to=hi[0];
            else{
                cout<<"NO\n";
                goto done;
            }

            while(q<p[v].size()){
                ans[p[v][q]]="ABC"[to];
                q++;
            }
        }

        cout<<"YES\n";
        for(char ch:ans) cout<<ch;
        cout<<"\n";

        done:;
    }

    return 0;
}