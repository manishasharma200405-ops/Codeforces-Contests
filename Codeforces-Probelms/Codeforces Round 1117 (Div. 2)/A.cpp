#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll; 
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,n) for(int i=0;i<n;i++)
int main (){
    fast_io
int t;cin>>t;

while(t--){
    int n,k;cin>>n>>k;
    bool wrd[26]={};
    rep(i,n){
        string s;cin>>s;
        wrd[s[0]-'a']=true;
    }
vector<string> a(k);
rep(i,k) cin>>a[i];
vector<bool> dn(k,false);
int cnt=0;
while(true){
    bool chg=false;
    rep(i,k){
        if(dn[i]){
            continue;

        }
        bool ok=true;
        for(char c: a[i]){
            if(!wrd[c- 'A']){
                ok=false;
                break;
            }
        }
        if(ok){
            dn[i]=true;
        cnt++;
    wrd[a[i][0] -'A']=true;
    chg=true;
    }
    }
    if(!chg) break;
}
cout<<(cnt==k? "Yes\n" : "No\n");
}
    return 0;
}