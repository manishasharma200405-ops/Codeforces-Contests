//div 2 
#include <bits/stdc++.h>
using namespace std;
/*
Author - Kenway-Connor
*/
typedef long long ll;


//#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,b) for(int i=0; i<=(b); i++)
#define rep1(i,a,b) for(int i=(a); i<=(b); i++)

int main(){

    int tt;
    cin >> tt;

    while(tt--){

        int n,q;
        cin >> n >> q;

        vector<int> a(n), o(n), p(n), m(n);

        rep(i,n-1) cin >> a[i];

        rep(i,n-1) o[i]=i;

        sort(o.begin(), o.end(), [&](int x,int y){
            if(a[x]!=a[y]) return a[x]<a[y];//x<y
            return x<y;
        });

        rep(r,n-1) p[o[r]]=r;

        int c=-1;
        rep(i,n-1){ c=max(c,p[i]); m[i]=c; }

        ll b=1;
        while(true){
            bool k=true;
            for(ll x=b;x<n;x+=b){
                if(m[x-1]!=x-1){ k=false; break; }
            }
            if(k) break;
            b*=2;
        }

        ll ans = (b==1)?0:b/2;
        cout << ans << "\n";
    

    }


     

    return 0;
}