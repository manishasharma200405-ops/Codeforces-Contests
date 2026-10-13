#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll ;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
int t;cin>>t;
 while(t--){
  ll n;
 cin>>n;
if(n==2){
cout<<"11\n";
continue;
        }// having contain msot 3 ones and min f(s);
ll tt=n+1;
 ll dv=tt/3, rm=tt%3;
  ll t1=0,t2=0,t3=0;
 int cn=0;

if(rm==0){
ll l0,l1,l2,l3;
 if(dv%2==0){
     l0=dv;
     l1=dv;
     l2=dv;
      //.........         
     t1=l0; t2=t1+l1;
     //.the cn .
  cn=2;
} else {
 l0=dv;l1=2;
 l2=dv;l3=dv-2;
     t1=l0; t2=t1+l1; t3=t2+l2;
     cn=3;
     }
 } else if(rm==1){
 ll l0,l1,l2;
 if(dv%2==0){ l0=dv;
    l1=dv;
    l2=dv+1;
 }
 else { l0=dv;
    l1=dv+1;
    l2=dv; }
     t1=l0; 
     t2=t1+l1;
            cn=2;
  } else {//pixels  a...
 if(dv==0){
                t1=1;
                cn=1;
            } else {
                ll l0,l1,l2;
                if(dv%2==0){ l0=dv+1;l1=dv;l2=dv+1; }
                else { l0=dv;l1=dv+1;l2=dv+1; }
                t1=l0; t2=t1+l1;
                cn=2;
            }
        }
// the simgle true case n=2
        string res(n,'0');
        res[t1-1]='1';
        if(cn>=2) res[t2-1]='1';
        if(cn>=3) res[t3-1]='1';
        cout<<res<<"\n";
    }
 


//time would be around..O(n);
  

return 0;
}