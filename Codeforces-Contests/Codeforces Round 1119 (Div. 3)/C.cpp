#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

int main(){
    fast_io

    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vector<int>a(n);
        vector<int>one,neg;

        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1)one.push_back(i);
            if(a[i]==-1)neg.push_back(i);
        }

        int l=-1,r=-1,best=0;

        if(one.empty()){
            if(!neg.empty()){
                l=neg.front();
                r=neg.back();
            }
        }
        else{
            for(int i=0;i+1<(int)one.size();i++){
                int x=one[i],y=one[i+1];
                if(y-x+1>best){
                    best=y-x+1;
                    l=x;
                    r=y;
                }
            }

            if(!neg.empty()&&neg.front()<one[0]){
                int x=neg.front(),y=one[0];
                if(y-x+1>best){
                    best=y-x+1;
                    l=x;
                    r=y;
                }
            }

            if(!neg.empty()&&neg.back()>one.back()){
                int x=one.back(),y=neg.back();
                if(y-x+1>best){
                    best=y-x+1;
                    l=x;
                    r=y;
                }
            }

            if(best==0){
                l=one[0];
                r=one[0];
            }
        }

        for(int i=0;i<n;i++){
            if(a[i]==-1)a[i]=0;
        }

        if(l!=-1)a[l]=1;
        if(r!=-1)a[r]=1;

        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }

    return 0;
}