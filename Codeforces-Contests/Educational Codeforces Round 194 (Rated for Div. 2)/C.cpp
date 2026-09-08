#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
       
 ll x,y;
        cin>>x>>y;

ll s=x+y;
ll z=0;

        for(int i=60;i>=0;i--){//x,y<2^29 we do not need 60 but its safe soo..
            if((s>>i)&1){//hate edges like tts edge ones . 
                ll v=z+(1LL<<i);
                if(v<=x) z=v;
            }
        }

        cout<<s<<" "<<x-z<<'\n';

    
    }
    return 0;
}