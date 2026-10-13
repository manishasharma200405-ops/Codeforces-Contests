#include <bits/stdc++.h>
using namespace std;


#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;
map<string,int>mp;
int ans=0;
    while (t--) {
      string s ; cin>>s;
      for(char &c :s ){
 c=tolower(c);

      }
      mp[s]++;
      ans=max(ans,mp[s]);

    }
    cout<<ans<<"\n";
    return 0;
}