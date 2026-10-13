#include <bits/stdc++.h>
using namespace std;


#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main (){
    fast_io

   int n;
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(i%2==1)sum +=a;
    }
    cout<<sum<<"\n";
    return 0;

    return 0;
}