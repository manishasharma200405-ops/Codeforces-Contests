
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
 const ll NEG = LLONG_MIN/2;
int main(){
    

    int tt; cin >> tt;
    while(tt--){
     int n;
    cin>>n;
    vector<int> pr(n+1,0);
    rep1(i,2,n) cin>>pr[i];
    vector<int> a(n+1);
    rep1(i,1,n) cin>>a[i];

    vector<vector<int>> baby(n+1);
    rep1(i,2,n) baby[pr[i]].pb(i);

    vector<int> ins;
    ins.reserve(n);
    ins.pb(1);
    fori(idx,0,(int)ins.size()){
        int v = ins[idx];
        for(int c : baby[v]) ins.pb(c);
    }

    vector<int> mn(n+1), mx(n+1), ct(n+1);
    bool k = true;

    for(int i=(int)ins.size()-1; i>=0; i--){
        int v = ins[i];
        if(baby[v].empty()){
            mn[v]=mx[v]=a[v];
            //int mx=[v]+??;
            // ct[v]=???;
            ct[v]=1;
        } else {
            int mnv = INT_MAX, mxv = INT_MIN, cv = 0;
            for(int c : baby[v]){
                mnv = min(mnv, mn[c]);
                mxv = max(mxv, mx[c]);
                cv += ct[c];
            }
            mn[v]=mnv; mx[v]=mxv; ct[v]=cv;
            if(mxv - mnv + 1 != cv) k = false;

            int m = baby[v].size();
            if(m >= 2){
                int dec = 0;
                rep(i,m){
                    int nxt = (i+1)%m;
                    //baby[v][i]>mn[baby[v][nxt]];
                    if(mn[baby[v][i]] > mn[baby[v][nxt]]) dec++;
                }
                if(dec > 1) k = false;
            } } }
cout << (k ? "YES" : "NO") << "\n";
   }    return 0;
}
