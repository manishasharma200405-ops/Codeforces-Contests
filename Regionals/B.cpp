#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    fast_io;
int n;
cin>>n;
int x=1000000;
int y=1000000;
int z=1000000;
for(int i=0;i<n;i++){
    vector<int > a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(),a.end());
    x=min(a[0],x);
    y=min(a[1],y);
    z=min(a[2],z);

}
cout<<x*y*z<<"\n";


    return 0;
}