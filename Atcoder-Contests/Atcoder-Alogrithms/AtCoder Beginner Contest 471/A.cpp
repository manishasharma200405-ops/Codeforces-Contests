#include <bits/stdc++.h>
using namespace std;


#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int a,b ; cin>>a>>b;
  int c=a+b;int d=a*b;int e=a-b;
 bool div = (a % b == 0 && a / b == 9);
  if (c==9 || d==9 || e==9 || div) cout<<"Nine"<<"\n";
  else cout<<"Nein"<<"\n";
    return 0;
}