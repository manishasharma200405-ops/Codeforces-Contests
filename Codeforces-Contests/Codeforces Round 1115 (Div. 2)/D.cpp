#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
//upsolving with edits
int main(){
    fast_io
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
          vector<ll> a(n);
          for(auto &x:a){
            cin>>x;
          }
         vector<ll> diff(n-1);
        for(int i=0;i<n-1;i++){
            diff[i]=a[i+1]-a[i];
        
        }  
        int l=0;
        while(l<n-1){
            int r=l;
            while(r+1<n-1 && ((diff[r] & 1) ==(diff[r+1] &1))){
                r++;
            }
            sort(diff.begin()+l, diff.begin()+r+1);
        l=r+1;
        }


        for(int i=1;i<n;i++){
            a[i]=a[i-1]+diff[i-1];

        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" \n"[i==n-1];
        }
    }
}