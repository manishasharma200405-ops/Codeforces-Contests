//Div 2
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)

const int N = 2e5+5;
int a[N];
ll x[N], y[N], g[N], s[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        rep1(i,1,n) cin >> a[i];

        x[0]=y[0]=0;
        rep1(i,1,n){
            x[i]=x[i-1]+(a[i]==1);
            y[i]=y[i-1]+(a[i]==3);
        }
        rep1(k,0,n) g[k]=2*y[k]-k;

        s[n]=LLONG_MAX; 
        for(int k=n-1;k>=1;k--)
            s[k]=min(s[k+1], g[k]);

        char r='N';
        rep1(l,1,n-2){
            if(2*x[l]<l) continue;
            if(s[l+1]>g[l]) continue;
            r='Y'; break;
        }

        cout << (r=='Y' ? "YES" : "NO") << "\n";
    }
}