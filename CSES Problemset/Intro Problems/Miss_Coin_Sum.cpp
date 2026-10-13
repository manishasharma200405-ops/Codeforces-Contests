#include <bits/stdc++.h>
 /*
 Manisha0369
 */
 using namespace std;
 typedef long long ll;
 #define fast_io ios_base:: sync_with_stdio(0);cin.tie(0);
 int main(){
    fast_io;

    int n ;cin>>n;
          vector<int> a(n);
          for(int i=0;i<n;i++){
            cin>>a[i];
          }
          sort(a.begin(),a.end());
          ll t=1;
             for(int i=0;i<n;i++)
{
    if(a[i]> t){
        break;
    }
    t+=a[i];
}
cout<<t<<"\n";

 }