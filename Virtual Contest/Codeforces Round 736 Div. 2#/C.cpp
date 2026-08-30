#include <bits/stdc++.h>
/*
  Player__
*/
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);



int main(){
    fast_io;
  
  
       int n,m;cin>>n>>m;
       //find weaker noble min (u,v);
       //add friend and remove then type 2
       vector<int> sf(n+1,0);
       int sur=n;
      for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;

        int weak =min(u,v);


        if(sf[weak]==0){
            sur--;
        }

        sf[weak]++;
      }
       int q;cin>>q;

       while(q--){

        int x;cin>>x;

        if(x==1){
            int u,v;cin>>u>>v;

            int weak=min(u,v);

            if(sf[weak]==0){
                sur--;
            }
            sf[weak]++;

        }else if(x==2){

            int u,v;cin>>u>>v;

            int weak=min(u,v);

            sf[weak]--;
            
            if(sf[weak]==0){
                sur++;
            }
          
        }else if(x==3){
            cout<<sur<<"\n";
        }
       }
return 0;
}