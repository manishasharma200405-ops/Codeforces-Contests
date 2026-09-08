#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
       
    int n;cin>>n;
     vector<int> a(n);
     for(int i=0;i<n;i++) cin>>a[i];

        if(a[0]==0&&a[n-1]==0){
            cout<<0<<'\n';
        }
        else{
            int z=0;
            for(int i=1;i<n-1;i++){
                if(a[i]==0) z++;
            }

            if(a[0]==1&&a[n-1]==1){
                if(z>=2) cout<<2<<'\n';
                else cout<<-1<<'\n';
            }
            else{
                if(z>=1) cout<<1<<'\n';
                else cout<<-1<<'\n';
            }
        }
    }
    return 0;
}