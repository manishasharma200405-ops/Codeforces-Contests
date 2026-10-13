#include <bits/stdc++.h>
using namespace std;
/*
author - player__
*/
//x macro 
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;
// seg treee 
struct seg{
    int n;
    vector<int> sm;
    vector<char> lz;
    void bld(vector<int>&a,int v,int l,int r){
        if(l==r){ sm[v]=a[l]; return; }
        int m=(l+r)/2;
        bld(a,2*v,l,m); bld(a,2*v+1,m+1,r);
        sm[v]=sm[2*v]+sm[2*v+1];
    }
    void ini(vector<int>&a){
        n=a.size();
        sm.assign(4*max(n,1),0);
        lz.assign(4*max(n,1),0);
        if(n) bld(a,1,0,n-1);
    }
    void ap(int v,int l,int r){ sm[v]=(r-l+1)-sm[v]; lz[v]^=1; }
    void psh(int v,int l,int r){
        if(lz[v]){
            int m=(l+r)/2;
            ap(2*v,l,m); ap(2*v+1,m+1,r);
            lz[v]=0;
        }
    }
    void upd(int v,int l,int r,int ql,int qr){
        if(qr<l||r<ql) return;
        if(ql<=l&&r<=qr){ ap(v,l,r); return; }
        psh(v,l,r);
        int m=(l+r)/2;
        upd(2*v,l,m,ql,qr); upd(2*v+1,m+1,r,ql,qr);
        sm[v]=sm[2*v]+sm[2*v+1];
    }//pt flip on s_k always d_{k-1 } like it toggle with it ? an if it exist thne .
    void flp(int l,int r){ if(l>r||!n) return; upd(1,0,n-1,l,r); }
    // yes turn otggle suffix of parity arr maintai a and o with a seg tree this one range flip and sum qry ,,
    ll tot(){ return n?sm[1]:0; }
};

void slv(){
    int n,q; cin>>n>>q;
    string s; cin>>s;

    vector<int> d(n,0);
    vector<ll> w(n,0);
    ll a=0;
    fr(i,1,n-1){
        d[i]=(s[i-1]!=s[i]);
        w[i]=(ll)i*(n-i);
        a+=(ll)d[i]*w[i];
    }

    vector<int> p(n,0);
    fr(j,1,n-1) p[j]=p[j-1]^d[j];

    seg tr; tr.ini(p);

    auto pw=[&]()->ll{
        ll o=tr.tot(), z=n-o;
        return (a+z*o)/2;
    };

    vector<ll> res;
    res.push_back(pw());

    rep(_,q){
        int k; cin>>k;
        if(k>1){
            int i=k-1, od=d[i];
            d[i]^=1;
            a+=w[i]*(ll)(d[i]-od);
            tr.flp(i,n-1);
        }
        if(k<n){
            int i=k, od=d[i];
            d[i]^=1;
            a+=w[i]*(ll)(d[i]-od);
            tr.flp(i,n-1);
        }
        res.push_back(pw());
    }

    rep(i,(int)res.size()) cout<<res[i]<<" \n"[i+1==(int)res.size()];
}

int main(){
    fast_io
    int t; cin>>t;
    while(t--) slv();
    return 0;
}