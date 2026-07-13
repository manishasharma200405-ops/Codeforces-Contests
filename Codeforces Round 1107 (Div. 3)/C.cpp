//good times good times
#include <iostream>
#include <string>

using namespace std;
int main(){
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        string s;cin>>s;
        int ans =0;
        for (int i=0;i<n-1;i++) { if(s[i]!=s[i+1]) ans++; }

        cout<<(ans==1 ? 2: 1)<<"\n";
         
        
        
    }
    return 0;
}