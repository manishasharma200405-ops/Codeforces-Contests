#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool ck(const string&s,ll x){
    ll l=0,r=0;
    int n=s.size();

    for(int i=0;i<n;i++){
        char c=s[i];

   if(c=='+'){
    ll nl,nr;
    if(l==r&&l>0){
       nl=max(1LL,l-x)+1;
       nr=l+x;
           }
   else{
     nl=max(1LL,l-x);
         nr=r+x;
            }

     if(nl>nr)return 0;
     l=nl;
     r=nr;
        }
        else if(c=='-'){
 ll nl,nr;
 if(l==r&&l<0){
     nr=min(-1LL,l+x)-1;
         nl=l-x;
            }
            else{
      nr=min(-1LL,r+x);
      nl=l-x;
            }

 if(nl>nr)return 0;
        l=nl;
     r=nr;
        }
else{
    if(l-x<=0&&0<=r+x)l=r=0;
    else return 0;
        }
    }

    return 1;
}
/*
binary searching over the min cost x and usese ck() to chekc whther cost is possible
ai<x
pi=pi-1 +ai
prefix sum move by at leasy 1 and most x 
store rnage of psosbile prefix sum 
l and r 

*/

bool ck1(const string&s){
    int n=s.size();

for(int i=0;i+1<n;i++){
        if(s[i]!='0'&&s[i+1]!='0'&&s[i]!=s[i+1])
            return 0;
    }

    int len=0;

 for(int i=0;i<n;i++){
        if(s[i]=='0'){
     if(len>0&&len%2==0)return 0;
            len=0;
        }
        else len++;
    }

    return 1;
}

/*
checking whether each sign +- 0 cna be satisified with a non 0 step at most x 
*/
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
       
    int n;
        string s;
        cin>>n>>s;

        bool bad=0;

        if(s[0]=='0')bad=1;

 for(int i=0;i+1<n;i++){
     if(s[i]=='0'&&s[i+1]=='0'){
           bad=1;
           break;
            }
        }

     if(bad){
    cout<<-1<<'\n';
            continue;
        }

 if(ck1(s)){
     cout<<1<<'\n';
            continue;
        }
  ll l=2,r=n+10;
     while(l<r){
            ll m=(l+r)/2;
            if(ck(s,m))r=m;
            else l=m+1;
        }

        cout<<l<<'\n';
    }
    return 0;
}