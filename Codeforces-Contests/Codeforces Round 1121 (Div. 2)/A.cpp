#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io
// any palindrome len >= 4 contains a palin of 2 or 3 palin len . 
string s ; cin>>s;
string ans="";
for (int i=0;i+1<s.size();i++){
    if(s[i]==s[i+1]){
        string x= s.substr(i,2);
        if(ans==""||      x <ans){
           ans =x;

        }
    }
}
    if(ans!= ""){
        cout<<ans<<"\n";return 0;
    }
    for(int i=0;i+2<s.size();i++){
        if(s[i]==s[i+2]){
            string x= s.substr(i,3);
            if(ans=="" || x<ans ){
                ans=x;
            }
        }
    }
    if(ans ==""){
        cout<<"-1"<<"\n";
    }else{
        cout<<ans<<"\n";
    }

  return 0;


}