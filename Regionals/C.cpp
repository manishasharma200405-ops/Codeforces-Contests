#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
typedef long long ll ;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    fast_io;

   ll n;cin>>n;
if(n==0) {cout<<0<<"\n"; return 0;}
    //converting to binary 
    vector<int > v;
    while(n>0){
        v.push_back(n%128);//take 7 bits

        n/=128; // remove 7 bits 
    }
    reverse(v.begin(),v.end());//we need tostart form right 
    for(int i=0;i<(int)v.size();i++){// print decimal form convert back to decimal form binary 
        if(i!=(int )v.size()-1){
            v[i]+=128;//never needed bin. con.
        }
        cout<<v[i]<<' ';
    }
    cout<<"\n";



    return 0;
}