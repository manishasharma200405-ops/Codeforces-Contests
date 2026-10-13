#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast_io;
    int n;cin>>n;
    int k;cin>>k;
    vector<int> cnt(k+1);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        cnt[x]++;


    }
    int mx=*max_element(cnt.begin()+1,cnt.end());
    int ans=0;
    for(int i=1;i<=k;i++){
        if(cnt[i]+1>=mx){
            ans++;
        }
    }
cout<<ans<<"\n";
    return 0;

    

}