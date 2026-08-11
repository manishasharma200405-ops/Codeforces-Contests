#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int n,q;
    cin>>n>>q;
    vector<int> a[2];//2d array for permutation of p(i) to p'(i) ( for inversion ops )
    a[0].resize(n+1);
    a[1].resize(n+1);
    rep(i,n){
        int p; cin>>p;
        a[0][i+1]=p;
        a[1][p]=i+1;
    }
    int c=0;
    rep(_,q){//processing qry
        int op; cin>>op;
        if(op==1){
            int x,y; cin>>x>>y;
            int d=1-c;
            int va=a[c][x], vb=a[c][y];
            swap(a[c][x],a[c][y]);//swap values of px and py
            swap(a[d][va],a[d][vb]);
        } else {
            c=1-c;
        }
    }
    for(int i=1;i<=n;i++) cout<<a[c][i]<<" \n"[i==n];// print values of p 
    return 0;
  
  

return 0;
}