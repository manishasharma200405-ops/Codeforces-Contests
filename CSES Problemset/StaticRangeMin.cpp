#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
const int MAXN =200005;
const int k=19;
int st[MAXN][k];
int arr[MAXN];
#define fast_io  ios_base::sync_with_stdio(0);cin.tie();
int main(){
    fast_io;
    //min range  queries
    int n,q;cin>>n>>q;
    vector<int > x(n);
    //find min in range a,b
  
    for(int i=0;i<n;i++){
        cin>>x[i];
        st[i][0]=x[i];
    }
    //precomputation 
    for(int j=1;j<k;j++){
    for(int i=0;i+(1<<j)-1<n;i++){
        st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);

    }
    }
    while(q--){
        int l,r;cin>>l>>r;
        l--;r--;
                    int len=r-l+1;
        int K=31- __builtin_clz(len);
        int ans=min(st[l][K],st[r-(1<<K)+1][K]);
        cout<<ans<<"\n";
    }
   return 0;

}