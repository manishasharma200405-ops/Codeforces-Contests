#include <bits/stdc++.h>
 /*
 Manisha0369
 */
 using namespace std;
 #define fast_io ios_base:: sync_with_stdio(0);cin.tie(0);
 int main(){
    fast_io;

int n,w;cin>>n>>w;
//min num of gnod. to be printed 
vector<int> a(n);
for(int i=0;i<n;i++){cin>>a[i];


}
sort(a.begin(),a.end());
int l=0; int h=n-1;int g=0;
while(l<=h){
    if(l!=h  && a[l]+a[h]<=w){
        l++;
    }
    h--;g++;
}

cout<<g++<<"\n";
 }