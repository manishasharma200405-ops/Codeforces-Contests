#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast_io;
    
    int n;cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=(n/2);i<n;i++){
       sum+=a[i];
    }
    cout<<sum<<"\n";

    return 0;



}