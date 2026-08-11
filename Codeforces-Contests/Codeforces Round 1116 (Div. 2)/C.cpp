#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

int tt;cin>>tt;
while(tt--){
      int n,k;cin>>n>>k;
        string s;cin>>s;

        int m=0,a=0,b=0;
        int z=2*n;

        for(int i=0;i<z;i++){
            if(s[i]=='1' && i%2)
                m++;

            if(s[i]=='1' && s[(i+1)%z]=='0'){
                if(i%2==0) a++;
                else b++;
            }
        }

        int r=m+a-b;
        int bl=0;

        for(char c:s)
            if(c=='1') bl++;

        bl-=r;

        cout<<r<<" "<<bl<<'\n';
}
 
    
    return 0;
}