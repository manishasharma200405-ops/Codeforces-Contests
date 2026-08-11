#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main (){
    fast_io

  int t;
    cin >> t;

    while (t--) {
      int n;cin>>n;
      string s;cin>>s;
       int d0=0,d1=0;
        vector<pair<char,int>> rn;
        int i=0;
        while(i<n){
            int j=i;
            while(j<n&&s[j]==s[i])j++;
            int c=j-i;
            rn.push_back({s[i],c});
            if(c>1){if(s[i]=='0')d0+=c-1;else d1+=c-1;}
            i=j;
        }
        int df=abs(d0-d1);
        int ans=d0+d1;
        if(df>1){
            int nd=df-1;
            char mn=(d0>d1)?'1':'0';//which one is bigger 
            int av=0;
            int m=rn.size();
            if(m>=1&&rn[0].first==mn)av++;
            if(m>=2&&rn[m-1].first==mn)av++;
            if(av<nd){cout<<-1<<"\n";continue;}
            ans+=nd;
        }
        cout<<ans<<"\n";
    }


    return 0;
}