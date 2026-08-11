#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
const int MOD=998244353;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

int tt;cin>>tt;
while(tt--){
    int n;cin>>n;
    string s ;cin>>s;
  int a=1,b=1;

  ///for even pos 
        for(int i=0;i<n;i+=2){
            int v=(i/2)%2;

            if(s[i]!='?' && s[i]-'0'!=v)
                a=0;

            if(s[i]!='?' && s[i]-'0'!=(v^1))
                b=0;
        }

        int c=1,d=1;

       //for odd pos  
        for(int i=1;i<n;i+=2){
            int v=((i-1)/2)%2;

            if(s[i]!='?' && s[i]-'0'!=v)
                c=0;

            if(s[i]!='?' && s[i]-'0'!=(v^1))
                d=0;
        }

        cout << 1LL*(a+b)*(c+d)%MOD << '\n';
    }
 
    
    return 0;
}