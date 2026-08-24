#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int q,v;cin>>q>>v;
  priority_queue<long long ,vector<long long >,greater<long long> > pq;
  long long cap=0;  
  while(q--){
int type=0;cin>>type;
if(type==1){
    long long t,w;cin>>t>>w;
   long long s=t-w;
   pq.push(s);
}else{
    long long t;cin>>t;
    while(!pq.empty() && pq.top()<= t-v){
        pq.pop();
        cap++;
    }if(cap>0){
        cout<<v<<"\n";
        cap--;
    }else if(!pq.empty()){
        long long s=pq.top();pq.pop();
        cout<<(t-s)<<"\n";
    }else{
        cout<<"-1"<<"\n";
    }
}
  }
    return 0;
}
