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
long long  n;cin>>n;


if(n==10) cout<<-1<<"\n";
else if (n%12==10) cout<<"22 "<<n-22<<"\n";
else{
     cout<<n%12<<" "  <<n-(n%12)<<"\n";

}

}
    
    return 0;
}