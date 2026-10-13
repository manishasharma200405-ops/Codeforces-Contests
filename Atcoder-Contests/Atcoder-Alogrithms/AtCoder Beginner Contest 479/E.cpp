#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
int main(){
    fast_io
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    vector<int> par(n+1,0),pe(n+1,0),sz(n+1,1),ord;
    ord.reserve(n);
    vector<int> st={1};
    par[1]=-1;
    while(!st.empty()){
        int v=st.back();
        st.pop_back();
        ord.push_back(v);
        for(auto [u,id]:g[v]){
            if(u==par[v])continue;
            par[u]=v;
            pe[u]=id;
            st.push_back(u);
        }
    }
    for(int i=n-1;i>0;i--){
        int v=ord[i];
        sz[par[v]]+=sz[v];
    }
    vector<ll> d(n+1,0);
    for(int v=2;v<=n;v++){
        int e=pe[v];
        if(sz[v]*2>n)d[v]+=e;
        else{
            d[1]+=e;
            d[v]-=e;
        }
    }
    vector<ll> x(n+1,0);
    for(int i=0;i<n;i++){
        int v=ord[i];
        if(v==1)x[v]=d[v];
        else x[v]=x[par[v]]+d[v];
    }
    for(int i=1;i<=n;i++)cout<<x[i]<<" \n"[i==n];
    return 0;
}