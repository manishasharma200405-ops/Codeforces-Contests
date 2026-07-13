#include <iostream>
using std::cin;
using std::cout;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
     int t;cin>>t;
     while(t--){
        int z,d;
        cin>>z>>d;
        cout<<(z%d==0 ? "Yes": "No")<<"\n";
     }


      return 0;
}