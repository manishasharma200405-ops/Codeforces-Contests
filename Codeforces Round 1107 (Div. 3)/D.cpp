//An Alternative Way

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int tt;cin>>tt;
    while(tt--){
      
         int n;cin>>n;
         vector<ll> a(n),b(n);
        
            for(int i=0;i<n;i++) cin>>a[i];
            for(int i=0;i<n;i++) cin>>b[i];
            // for(int i=0;i<n;i++){
            //     if(a[i]%2==0) a[i]--;
            //     else a[i]++;
            // }
            for (int i= 1;i<n;i++){
                a[i]+=a[i-1];
               b[i]+=b[i-1];
            }
            // for(int i=1;i<n;i++){
            //     b[i]+=b[i-1];
            // }
           bool res=1;
            for(int i=0;i<n;i++){
            //    if(a[i]==b[i]) res=0;
                if(a[i]>b[i]) res=0;
            }
            if(res) cout<<"YES\n";
            else cout<<"NO\n";

        
        
    }
    return 0;
}