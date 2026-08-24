#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int n;cin>>n;
  set<long long > s;
  for(int i=0;i<n;i++){
   long long x;cin>>x;
   s.insert(x);

  }
  long long cur=0;
  long long ans=0;
  while(!s.empty()){
    auto it =s.upper_bound(cur);
    bool left=false;
    if(it==s.begin()){
        left=false;
    }
    else if(it==s.end()){
        left=true;
    }
    else{
        long long right=*it; long long l=*prev(it);
        long long dl=cur-l;
        long long dr=right-cur;left=(dl <=dr);
    }
    long long nxt;
    if(left){
        --it;
        nxt=*it;

    }else{
        nxt=*it;
    }
    ans+=abs(cur-nxt);cur=nxt;
    s.erase(nxt);
  }
  cout<<ans<<"\n";

    return 0;
}
