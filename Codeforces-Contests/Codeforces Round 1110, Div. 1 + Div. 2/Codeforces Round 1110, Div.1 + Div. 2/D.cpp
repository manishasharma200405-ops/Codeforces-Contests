
 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;
 #define rep(i,n) for(int i=0;i<n;i++)
 #define rep1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
int  toss[2005][2005];

int main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0);

    int tt; cin >> tt;
    while(tt--){
         int n; ll m;
        cin >> n >> m;
         rep1(i,1,n) rep1(j,1,n) toss[i][j] = 0;

        rep1(k,1,m){
            int d,b,j; cin >> d >> b >> j;
            toss[b][j] = d;
        }

        vector<int> sine(n+1);
        rep1(i,1,n) sine[i] = toss[i][i];
        

        vector<vector<int>> ton(n+1);
        vector<int> degn(n+1, 0);
        bool kol = true;

        rep1(i,1,n){
            rep1(j,i,n){
                if(i==j) continue;
                //int d=toss[i][j];
                int o = toss[i][j];
                int si = sine[i], sj = sine[j];
                

                if(si==1 && sj==1){
                    if(o==2) kol = false;
                } else if(si==2 && sj==2){
                    if(o==1) kol = false;
                } else {//int sun=(s==1) ?j:i;
                    int pus = (si==1) ? i : j;
                    int nog = (si==1) ? j : i;

                    if(o==1){ ton[nog].pb(pus); degn[pus]++; }
                    else    { ton[pus].pb(nog); degn[nog]++; }
                }
            }
        }

        vector<int> com;
        if(kol){
            queue<int> q;
            rep1(i,1,n) if(degn[i]==0) q.push(i);
            while(!q.empty()){
                int u = q.front(); q.pop();
                com.pb(u);
                for(int v : ton[u]) if(--degn[v]==0) q.push(v);
            }
            if((int)com.size() != n) kol = false;
        }

        if(!kol){
            cout << "NO\n";
        } else {
            vector<ll> a(n+1);
            int r = 1;
            for(int i : com) a[i] = (sine[i]==1 ? r : -r), r++;

            cout << "YES\n";
            rep1(i,1,n) cout << a[i] << " \n"[i==n];
        }
    }        return 0;
}
