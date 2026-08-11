#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

 int n;cin>>n;
 while(n--){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b ||b==c ||a==c){ cout<<"0"<<"\n";
        continue;

    }
    int cnt=0;
    while(a!=b && b!=c && a!=c){
        if(a>b &&a>c){
            a--;
            if(b<c) b++;
            else c++;
        }
        else if(b>a && b>c){
            b--;
            if(a<c) a++;
            else c++
;        }
            else{
                c--;
                if(a<b) a++;
               else  b++;

            } 
            cnt++;
}
cout<<cnt<<"\n";
    
    
 }
  
  

return 0;
}