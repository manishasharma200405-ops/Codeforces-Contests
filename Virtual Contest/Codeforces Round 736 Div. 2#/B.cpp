#include <bits/stdc++.h>
/*
  Player__
*/
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);



int main(){
    fast_io;
    int tt;cin>>tt;
      while(tt--){
       int n;cin>>n;
       string a,b;
       cin>>a>>b;

     //  vector<bool> arr(n);
       int cnt=0;
      
        for(int j=0;j<n;j++){
           if(b[j]=='1'){
            if(j>0 && a[j-1]=='1'){
                cnt++;
                a[j-1]='0';
            }
            else if(a[j]=='0'){
                cnt++;
                a[j]='2';

            }else if(j<n-1 && a[j+1]=='1'){
                cnt++;
                a[j+1]='0';
            }
           }
        }
        cout<<cnt<<"\n";
       

      }
      return 0;

}