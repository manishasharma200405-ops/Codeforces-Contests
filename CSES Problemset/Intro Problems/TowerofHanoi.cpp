#include <bits/stdc++.h>
 /*
 Manisha0369
 */
 using namespace std;
 typedef long long ll;
 #define fast_io ios_base:: sync_with_stdio(0);cin.tie(0);
  void toh(int n,int p,int fp,int ap){
    if(n==0){
        return ;
    }
    toh(n-1,p,ap,fp);
    cout<<p<<" "<<fp<<"\n";
    toh(n-1,ap,fp,p);

  }
 
 
 int main(){
    fast_io;
int n;cin>>n; 

//using bitwise doing 2^n-1 
int k=(1<<n)-1;
cout<<k<<"\n";

  toh(n,1,3,2);

    return 0;
}