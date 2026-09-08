#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
vector<ll> sg;

void up(int i, ll v, int nd, int l, int r){
    if(l==r)
    {
        sg[nd]=v;
        return;
    }
    int m=(l+r)>>1;
    if(i<=m)
        up(i,v,nd<<1,l,m);
    else
        up(i,v,nd<<1|1,m+1,r);
    sg[nd]=max(sg[nd<<1],sg[nd<<1|1]);
}

int qr(int ql,int qh,int nd,int l,int r){
    if(qh<l||r<ql||sg[nd]<=0)
        return -1;
    if(l==r)
        return l;
    int m=(l+r)>>1;
    int x=qr(ql,qh,nd<<1|1,m+1,r);
    if(x!=-1)
        return x;
    return qr(ql,qh,nd<<1,l,m);
}

int main(){
    fast_io

    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vector<int>a(n);
 for(int i=0;i<n;i++)cin>>a[i];

        string s;cin>>s;

        ll k=0;
        for(int x:a)k+=x;

        ll ans=0,ct=0;
        for(int i=0;i<n;i++)
        {
            if(a[i])
                ct++;
            else
           ans+=ct;
        }

   cout<<ans<<" ";

  if(k==0)
        {
            for(int i=0;i<n;i++)
                cout<<ans<<" ";
            cout<<"\n";
            continue;
        }

        int K=(int)k;
        int sz=K+1;
        vector<ll> d(sz);
/*
to track gaps array btw . 1's  where d[i]=num of 0s btw i and i+1
*/
        int p=-1;
        int id=0;
for(int i=0;i<n;i++)
        {
            if(a[i])
            {
                if(p==-1)
                    d[id]=i;
                else
                    d[id]=i-p-1;
                id++;
                p=i;
            }
        }
        d[id]=n-p-1;

        ll Z=n-k;

        sg.assign(4*sz,0);
        for(int i=0;i<sz;i++)
            up(i,d[i],1,0,sz-1);

        int f=0;

        for(char c: s){
            if(c=='1')
            {
                ll x=Z-d[f];
                if(x!=0)
                {
                    ans-=x;
                    int nf=(f+1)%sz;
                    ll mg=d[f]+d[nf];
                    d[f]=0;
                    up(f,0,1,0,sz-1);
                    d[nf]=mg;
                    up(nf,mg,1,0,sz-1);
                    f=nf;
                }
            }
            else
            {
                int ps=-1;
                if(f-1>=0)
                    ps=qr(0,f-1,1,0,sz-1);
                if(ps==-1&&f+1<=sz-1)
                    ps=qr(f+1,sz-1,1,0,sz-1);

                if(ps!=-1)
                {
                    int lg=(ps-f+sz)%sz;
                    ans-=lg;
                    d[ps]-=1;
                    up(ps,d[ps],1,0,sz-1);
                    d[f]+=1;
                    up(f,d[f],1,0,sz-1);
                }
            }

            cout<<ans<<" ";
        }

        cout<<"\n";
    }

    return 0;
}