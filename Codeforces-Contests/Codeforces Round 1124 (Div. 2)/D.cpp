#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/

#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int vv[8]={0,3,5,6,9,10,12,15};
int xi[8][8];
int vi[16];
int fv[16][8];
int z;

void cb(int*a,int*b,int*r){
    for(int u=0;u<8;u++){
        int m=-1000000;
        int*w=xi[u];
        for(int k=0;k<8;k++){
            int c=a[k]+b[w[k]];
            if(c>m)m=c;
        }
        r[u]=m;
    }
}

int main (){
    fast_io

    for(int i=0;i<8;i++) vi[vv[i]]=i;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            xi[i][j]=vi[vv[i]^vv[j]];
    for(int a=0;a<16;a++)
        for(int i=0;i<8;i++)
            fv[a][i]=((a^vv[i])%3==0)?1:0;
    z=vi[0];

    int t;
    cin >> t;

    while (t--) {

        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        vector<int> tr(2*n*8);
        for(int i=0;i<n;i++){
            int*lf=&tr[(n+i)*8];
            for(int k=0;k<8;k++) lf[k]=fv[a[i]][k];
        }
        for(int i=n-1;i>=1;i--)
            cb(&tr[(2*i)*8],&tr[(2*i+1)*8],&tr[i*8]);

        cout<<tr[1*8+z]<<' ';

        for(int j=0;j<q;j++){
            int p,x;
            cin>>p>>x;
            p--;
            int po=n+p;
            int*lf=&tr[po*8];
            for(int k=0;k<8;k++) lf[k]=fv[x][k];
            po>>=1;
            while(po>=1){
                cb(&tr[(2*po)*8],&tr[(2*po+1)*8],&tr[po*8]);
                po>>=1;
            }
            cout<<tr[1*8+z]<<' ';
        }
        cout<<'\n';

    }
    return 0;
}