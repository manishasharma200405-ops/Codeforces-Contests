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
//h<max(??)..mod n..
int n;cin>>n;
vector<int > a(n);
//sort??
for(int i=0;i<n;i++){
    cin>>a[i];

}
//sort(a.begin(),a.end());
//we take max val of our new val
for(int s=0;s<n;s++){
    vector<int > w1(n),w2(n),w(n);
    for(int i=1;i<n;i++){
  w1[(s+i)%n]= max(w1[(s+i-1)%n],a[(s+i-1)%n]);

    }
    for(int i=1;i<n;i++){
        w2[(s+n-i)%n]= max(w2[(s+n-i+1)%n], a[(s+n-i)%n]);

    }
    for(int  i=0;i<n;i++){
        w[i]=min(w1[i],w2[i]);

    }
    cout<<accumulate(w.begin(),w.end(),0LL)<<" ";
}
cout<<"\n";

}

    return 0;
}