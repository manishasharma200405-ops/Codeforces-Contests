#include <bits/stdc++.h>
/*
  Player__
*/
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);

//global vars
const int x=5000;
int n;
int l[x+10],r[x+10],u[x+10],v[x+10];
bool check(int m){
    int j=1;
    for(int i=1;i<=n && j<=m;++i){
        int y=m-j+1;
        if((j<l[i] || j>r[i]) && (y<u[i] || y>v[i])) ++j;

    }
    return j==m+1;

}
void slv(){
    cin>>n;
    for(int i=1;i<=n;i++){
       
        cin>>l[i]>>r[i]>>u[i]>>v[i];

       }

      for(int m=n;m>=1;--m){
                if(!check(m)) continue;
                cout<<m<<"\n";
                return ;
      }
      cout<<0<<"\n";
}

int main(){
    fast_io;
    int tt;cin>>tt;
      while(tt--){
      slv();
      }
return 0;
}