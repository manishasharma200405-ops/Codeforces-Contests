#include <bits/stdc++.h>
/*
  Player__
*/
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);



int main(){
    fast_io;
    int tt;cin>>tt;
      while(tt--){
        int p;cin>>p;
        if(p%2==1){
            cout<<2<<" "<<p-1<<"\n";
        }
        else{
            cout<<3<<" "<<p-1<<"\n";
        }
      }

}