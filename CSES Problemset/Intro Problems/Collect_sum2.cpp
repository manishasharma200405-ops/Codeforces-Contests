#include <bits/stdc++.h>
 /*
 Manisha0369
 */
 using namespace std;
 #define fast_io ios_base:: sync_with_stdio(0);cin.tie(0);
 int main(){
    fast_io;
    int n,m;cin>>n>>m;
    //sort(a.begin(),a.end());
   /*
    maintian og pos
    */
    vector<int> a(n+1);
    vector<int> pos(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;

    }

    int p=1;
    for(int i=2;i<=n;i++){
      if(pos[i]<pos[i-1]){
         p++;
      }
    }
    while (m--){
        int i,j;
        cin>>i>>j;
       int  x=a[i];
       int y=a[y=a[j]];
       x=a[i];y=a[j];
        set<pair<int,int>> pr;
        if(x>1) pr.insert({x-1,x});
        if(x<n) pr.insert({x,x+1});
        if(y>1)pr.insert({y-1,y});
        if(y<n) pr.insert({y,y+1});
    
        for(auto v:pr){
            if(pos[v.second]<pos[v.first]){
                p--;
            }
        }
        swap(a[i],a[j]);
        swap(pos[x],pos[y]);
         for(auto v:pr){
            if(pos[v.second]<pos[v.first]){
                p++;
            }
        }
        cout<<p<<"\n";
    }
    return 0;
 }