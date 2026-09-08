#include <bits/stdc++.h>
/*
  Player__
*/
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);


int main(){
    fast_io;
    int tt;cin>>tt;
      while(tt--){
    int n, k; cin>>n>>k;
	 if(n>1 && k==n-1){ cout<<-1<<"\n"; continue;
	 }

	 k=n-k;
	 int cnt0=(n+1)/2,cnt1=n/2;
	 for(int i=1;i<=k;i++){
		if(i &1){
			if(i+2>k){
				while(cnt0--) cout<<0;
			}
			else{
				--cnt0;
				cout<<0;
			}

		}
		else{
			if(i+2>k){
				while(cnt1--) cout<<1;
			}else{
				--cnt1;
				cout<<1;
			}
		}
	 }
	 cout<<"\n";
      }
	  return 0;

}