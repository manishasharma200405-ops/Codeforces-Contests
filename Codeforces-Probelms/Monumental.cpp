#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
/*
an editoral slv
*/
  int tt;cin>>tt;
  while(tt--){
   int n ;cin>>n;
   vector<int > a(n);
   for(int i=0;i<n;i++){
    cin>>a[i];

   }
   multiset<int> ms(a.begin(),a.end());
   int lo=0,r=n+1;
   while(lo<r){
    int mid=(lo+r)/2;
    assert((int)ms.size()==n);
    bool ok=1;
    vector<int> rem;
    for(int i=mid-1;i>=0;i--){
        if(ms.count(i)){
            rem.push_back(i);
            ms.erase(ms.find(i));
            continue;
        }
        else{
            int x=*ms.rbegin();
            if(x<2*i+1){
                ok=0;
                break;
            }
            rem.push_back(x);
            ms.erase(ms.find(x));
        }
    }
    for(auto& z:rem) ms.insert(z);
    if(ok) lo=mid+1;
    else r=mid;
   }
   assert(lo>0);
   --lo;
   cout<<lo<<"\n";
  }
    return 0;
}