#include <bits/stdc++.h>
 /*
 Manisha0369
 */
 using namespace std;
 #define fast_io ios_base:: sync_with_stdio(0);cin.tie(0);
 int main(){
    fast_io;
    int n;cin>>n;
    //sort(a.begin(),a.end());
   /*
    maintian og pos
    */
    vector<int> pos(n+1);
    
    for(int i=0;i<n;i++){
int val;cin>>val;
pos[val]=i;
    }
    int p=1;
    for(int i=2;i<=n;i++ ){
      if(pos[i]<pos[i-1]){
         p++;
      }
    }
    cout<<p<<"\n";

 }