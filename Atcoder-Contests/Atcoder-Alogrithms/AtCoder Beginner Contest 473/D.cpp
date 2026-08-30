#include <bits/stdc++.h>
using namespace std;
/*
Player__
*/
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,k;
vector<int> a;
void dfs(int pos , int rem){
    if(pos==n-1){
        int cof=pos+1;
        if(rem %cof ==0){
            a[pos]=rem/cof;
            for(int x:a){
                cout<<x<<' ';

            }
            cout<<"\n";
        }
        return;
    }
    for(int x=0;(pos+1)*x<=rem;x++){
                  a[pos]=x;
                  dfs(pos+1,rem-(pos+1)*x);
    }

}
int main(){
    fast_io;
    
    cin>>n>>k;
 a.resize(n);
 dfs(0,k);
return 0;
}