
//Div 3 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back

int main(){
    

    int tt; cin >> tt;
    while(tt--){
        int n,x,y;cin>>n>>x>>y;
vector<int> p(n + 1);
        rep1(i,1,n) cin >> p[i];

        vector<vector<int>> g(n + 1);

        rep1(i,1,n) {
            if (i + x <= n) {
                g[i].pb(i + x);
                //g[i].pb(i+n);
                g[i + x].pb(i);


            }
            if (i + y <= n) {
                g[i].pb(i + y);
                //g[i+y].pb(n);
                g[i + y].pb(i);
            }
        } vector<int> c(n + 1);
        int id = 0;

        rep1(i,1,n) {
            if (c[i]) continue;
//
 id++;
 queue<int> q;

q.push(i);
c[i] = id;

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                for (int u : g[v]) {
                    if (!c[u]) {c[u] = id;
                        q.push(u);
                    } }}
        } bool k = 1;
        rep1(i,1,n) {
            if (c[i] != c[p[i]]) {k = 0;
                break;}
            
        }

        cout << (k ? "YES" : "NO") << '\n';
    
        }    return 0;
}
