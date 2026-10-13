#include <bits/stdc++.h>
using namespace std;
int main (){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int > p(n);
        for(int &x: p ){
        cin>>x;
        }
        int m=n/2;
        int mx1=0,mn1=n+1;
        int mx2=0,mn2=n+1;
        for(int i=0;i<m;i++){
            mx1=max(mx1,p[i]);
            mn1=min(mn1,p[i]);

        }
        for(int i=m;i<n;i++){
            mx2=max(mx2,p[i]);
            mn2=min(mn2,p[i]);
        }
          
        if(mx1< mn2 || mn1>mx2){
            cout<<1<<"\n";

        
        cout<<n<<' ';
        for(int x:p) cout<<x<<' ';
        cout<<"\n";
        continue;
    }
    vector<int> a,b;
    for(int i=0;i<n;i++){
        if(i<m){
            if(p[i]<=m)
                a.push_back(p[i]);

            
            else
                b.push_back(p[i]);
            
            
        }else{
            if(p[i]> m)
                   a.push_back(p[i]);
            
            else 
                b.push_back(p[i]);
            
        }
    }
        cout<<2<<"\n";
        cout<<a.size()<<' ';
             for(int x:a) 
                  cout<<x<<' ';
        cout<<"\n";
        cout<<b.size()<<' ';
              for(int x:b)
                  cout<<x<<' ';
        cout<<"\n";
    }

    return 0;
}