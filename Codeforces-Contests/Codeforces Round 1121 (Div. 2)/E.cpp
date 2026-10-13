#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=2005,M=1999005,P=3998005,p=998244353;
/*
rnaodmly permute b orderdd pair of bs l and k will be to pos i and j we cna do sort and acine it in 
O(n^2 log n) .....
*/
struct frac{
    int x,y;
    bool operator<(const frac&t)const{
        return x*1ll*t.y<t.x*1ll*y;
    }
};

int pw(int x,int k){
    int r=1;
    for(;k;k>>=1,x=x*1ll*x%p)
        if(k&1) r=r*1ll*x%p;
    return r;
}
int main(){
    fast_io
    int t;cin>>t;
    while(t--){
  int n,m=0,q=0,a[N],b[N];
 ll sum=0;
 frac u[M],v[P];

 cin>>n;
 for(int i=1;i<=n;i++) cin>>a[i];
 for(int i=1;i<=n;i++) cin>>b[i];

 for(int i=1;i<n;i++)
     for(int j=i+1;j<=n;j++)
          u[++m]={a[i],a[j]};

    sort(u+1,u+m+1);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    v[++q]={b[i],b[j]};

    sort(v+1,v+q+1);

 for(int i=1,j=0;i<=m;i++){
            while(j<q&&v[j+1]<u[i]) j++;
            sum+=j;
        }

  cout<<sum%p*pw(n*(n-1),p-2)%p<<"\n";
    }
 return 0;
}
