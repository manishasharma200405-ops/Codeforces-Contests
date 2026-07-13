//good times good times
#include <iostream>
using std::cin;
using std::cout;
int main(){
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        int y=1;
        while(n>0){
         //   y*=n%10;
            y*=10;
            n/=10;

        }
        cout<<y+1<<"\n";
    }
    return 0;
}