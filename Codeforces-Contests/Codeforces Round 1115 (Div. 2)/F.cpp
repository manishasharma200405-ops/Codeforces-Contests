#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
typedef long long ll;
 #define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
 const int LOG =20 ;
 int n,timer;
 vector<vector<int>> g,col,up;
 vector<int> tin,tout,dep,cnt;
 void dfs(int u,int p){
    tin[u]=++timer;
    up[u][0]=p;
    for(int i=1;i<LOG;i++)
        up[u][i]=up[up[u][i-1]][i-1];
        for(int v: g[u]){
            if(v==p) continue;
            dep[v]=dep[u]+1;
            dfs(v,u);
        }
        tout[u]=++timer;
    }
    
    bool anc(int u,int v){
        return tin[u]<=tin[v] && tout[v] <= tout[u];
    }

int lca(int u, int v ){
    if(anc(u,v)) return u;
     if(anc(v,u)) return v;
     
     for(int j=LOG-1;j>=0;j--){
        if(!anc(up[u][j],v))
        u=up[u][j];
     }
    return up[u][0];
     

}
void slv(){
    cin>>n;
    g.assign(n+1,{});
    col.assign(n+1,{});
    up.assign(n+1,vector<int> (LOG) );
    tin.assign(n+1,0);
    tout.assign(n+1,0);
    dep.assign(n+1,0);
    cnt.assign(n+1,0);
     vector<int> clrs(n+1),k(n+1);

    
    for(int i=1;i<=n;i++){
        cin>>clrs[i];
        col[clrs[i]].push_back(i);
    }

    
    for(int i=1;i<=n;i++)
        cin>>k[i];

   
    for(int i=1;i<n;i++){

        int u,v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    timer =0;
    dfs(1,1);
    vector<ll> ans(n +1,-1);
    for(int c=1;c<=n;c++){
        if(col[c].empty()) continue;
        int m=col[c].size();
        vector<int >  v=col[c];
        sort(v.begin(),v.end(),[&](int x, int y)
    {
        return tin[x]<tin[y];
    });

    int sz=v.size();
    for(int i=0;i<sz-1;i++){
        v.push_back(lca(v[i],v[i+1]));
    }
        sort(v.begin(),v.end(),[&](int x,int y){
            return tin[x]<tin[y];
        });
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int x: col[c]) cnt[x]=1;
        vector<pair<int,int >> edge;
        vector<int > st;
        for(int u:v){
       while(!st.empty() && !anc(st.back(),u))
              st.pop_back();
        
              
        if(!st.empty()){
            edge.push_back({st.back(),u});

        }   
        st.push_back(u);   
        }

        ll total=0;
        vector<pair<ll,ll>> w;
        for(int i=(int )edge.size()-1;i>=0;i--){
            auto[p,u]=edge[i];
            cnt[p]+=cnt[u];
            ll x= cnt[u];
            ll weight=min(x,(ll)m-x);
            ll len=dep[u]-dep[p];
            total +=weight*len;
            w.push_back({weight,len});
        }
        sort(w.rbegin(),w.rend());
        ll need=k[c]-1;
    ll save=0;
for( auto [weight,len]:w){
    ll take =min(need,len);
    save +=take * weight;
    need-=take;
    if(need==0) break;

}
ans[c]=total-save;
for(int u:v)cnt[u]=0;


}
for(int i=1;i<=n;i++){
    cout<<ans[i]<<" \n"[i==n];
}
    }



int main(){
    fast_io;
    int t;cin>>t;
    while (t--){
        slv();
    }
    return 0;
}

 