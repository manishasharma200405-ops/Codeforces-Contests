#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    fast_io;
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vector<int> b(n);
        for(auto &x:b)
            cin>>x;
        vector<int> df(n+2,0);
        vector<char> fr(n,0);

    /*  
    
    it has O (n) cons. algo. using tow pass bfs .
    but the forbidden status pos depends on og knowns val we use diff. arr .....
    */
        for(int i=0;i<n;i++){
            if(b[i]==0)
                fr[i]=1;
            else if(b[i]>0){
                int v=b[i],lo=max(0,i-v+1),hi=min(n-1,i+v-1);
                df[lo]++;
                df[hi+1]--;
            }
        }
        vector<char> fb(n,0);
        int cur=0;
        for(int i=0;i<n;i++){
            cur+=df[i];
            fb[i]=cur>0;
        }
        bool bd=false;
        for(int i=0;i<n;i++){
            if(fr[i]&&fb[i]){
                bd=true;
                break;
            }
        }
        if(!bd){
            for(int i=0;i<n&&!bd;i++){
                if(b[i]>0){
                    int v=b[i],L=i-v,R=i+v;
                    bool lo=L>=0&&!fb[L],ro=R<=n-1&&!fb[R];
                    if(!lo&&!ro){
                        bd=true;
                        break;
                    }
                    if(lo)
                        fr[L]=1;
                    else
                        fr[R]=1;
                }
            }
        }
        if(bd){
            cout<<-1<<"\n";
            continue;
        }
        bool an=false;
        for(int i=0;i<n;i++){
            if(fr[i]){
                an=true;
                break;
            }
        }
        if(!an)
            fr[0]=1;
        int IF=n+10;
        vector<int> d(n,IF);
        for(int i=0;i<n;i++){
            if(fr[i])
                d[i]=0;
        }
        for(int i=1;i<n;i++)
            d[i]=min(d[i],d[i-1]+1);
        for(int i=n-2;i>=0;i--)
            d[i]=min(d[i],d[i+1]+1);
        bool ok=true;
        for(int i=0;i<n;i++){
            if(b[i]!=-1&&d[i]!=b[i]){
                ok=false;
                break;
            }
        }
        if(!ok){
            cout<<-1<<"\n";
            continue;
        }
        string s(n,'0');
        for(int i=0;i<n;i++){
            if(fr[i])
                s[i]='1';
        }
        cout<<s<<"\n";
    }
    return 0;
}