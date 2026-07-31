
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
      int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> pr(n+1,0);
    rep1(i,1,n-1){
        int t = (s[i-1]!=s[i] ) ? 1 : 0;
        // ll t =(s[i] !=s[i-1]) ?1 : -1;
        pr[i]=pr[i-1]+
        (t==0  ? 1 : 0 );
    }
    if(n>=1) pr[n]=pr[n-1];
    //pr[i]=pr[n-1];
    rep(i,q){
        int l,r,k;

        cin>>l>>r>>k;
        if(l==r){
            cout<<"YES\n";
            continue;
        }
        int rec = pr[r-1]-pr[l-1];
        
        if(rec <= 2*k) cout<<"YES\n";
        else cout<<"NO\n";
    }

          
    
        }    return 0;
}
