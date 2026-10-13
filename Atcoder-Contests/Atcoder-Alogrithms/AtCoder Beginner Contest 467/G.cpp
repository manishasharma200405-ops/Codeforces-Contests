//ABC 467 
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
#define fori(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,b) for(int i=0;i<=b;i++)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define sz(x) (int)(x).size()
//global vars 
int n,q;
vector<ll> a;
vector<int> qc,ql,qr;
vector<ll> qx,qk;
vector<vector<int>> ch,po,qa;
vector<vector<ll>> lv,fc,fs;
vector<ll> cv;

int li(int j, ll v){
    return lb(all(lv[j]),v)-lv[j].begin()+1;
}
void upd(int j,int idx,ll cd,ll sd){
    int s=sz(lv[j]);
    for(int x=idx;x<=s;x+=x&(-x)){ fc[j][x]+=cd; fs[j][x]+=sd; }
}
void qp(int j,int idx,ll &c,ll &s){
    c=0; s=0;
    for(int x=idx;x>0;x-=x&(-x)){ c+=fc[j][x]; s+=fs[j][x]; }
}
vector<int> pfx(int r){
    vector<int> v;
    for(int x=r;x>0;x-=x&(-x)) v.pb(x);
    return v;
}
void csge(vector<int>&nd, ll T, ll &c, ll &s){
    c=0; s=0;
    for(int j: nd){
        int sz_=sz(lv[j]);
        if(!sz_) continue;
        int idx=lb(all(lv[j]),T)-lv[j].begin()+1;
        ll tc,ts,pc,ps;
        qp(j,sz_,tc,ts);
        qp(j,idx-1,pc,ps);
        c+=tc-pc; s+=ts-ps;
    }
}
void rsge(vector<int>&nR, vector<int>&nL, ll T, ll &c, ll &s){
    ll c1,s1,c2,s2;
    csge(nR,T,c1,s1);
    csge(nL,T,c2,s2);
    c=c1-c2; s=s1-s2;
}
void up(int p, ll nv){
    ll ov=cv[p];
    for(int j: ch[p]){
        upd(j, li(j,ov), -1, -ov);
        upd(j, li(j,nv), 1, nv);
    }
    cv[p]=nv;
}
ll sv(int l,int r,ll k){
    vector<int> nR=pfx(r), nL=pfx(l-1);
    ll cA,sA;
    rsge(nR,nL,1,cA,sA);
    if(sA<k) return -1;
    ll lo=1, hi=(ll)2e9;
    while(lo<hi){
        ll mid=lo+(hi-lo+1)/2;
        ll c,s;
        rsge(nR,nL,mid,c,s);
        if(s>=k) lo=mid; else hi=mid-1;
    }
    ll T=lo;
    ll cGE,sGE,cGT,sGT;
    rsge(nR,nL,T,cGE,sGE);
    rsge(nR,nL,T+1,cGT,sGT);
    ll rem=k-sGT;
    ll cEq=cGE-cGT;
    ll need=(rem+T-1)/T;
    if(need>cEq) need=cEq;
    return cGT+need;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    a.assign(n+1,0);
    rep1(i,1,n) cin >> a[i];

    qc.assign(q+1,0); ql.assign(q+1,0); qr.assign(q+1,0);
    qx.assign(q+1,0); qk.assign(q+1,0);
    rep1(i,1,q) cin >> qc[i] >> qx[i] >> ql[i] >> qr[i] >> qk[i];

    qa.assign(n+1,{});
    rep1(i,1,q) qa[qc[i]].pb(i);

    ch.assign(n+1,{});
    rep1(i,1,n) for(int j=i;j<=n;j+=j&(-j)) ch[i].pb(j);

    po.assign(n+1,{});
    rep1(i,1,n) for(int j: ch[i]) po[j].pb(i);

    lv.assign(n+1,{});
    rep1(j,1,n){
        for(int p: po[j]){
            lv[j].pb(a[p]);
            for(int i: qa[p]) lv[j].pb(qx[i]);
        }
        sort(all(lv[j]));
        lv[j].erase(unique(all(lv[j])),lv[j].end());
    }

    fc.assign(n+1,{}); fs.assign(n+1,{});
    rep1(j,1,n){
        int s=sz(lv[j]);
        fc[j].assign(s+1,0);
        fs[j].assign(s+1,0);
    }

    cv.assign(n+1,0);
    rep1(i,1,n) cv[i]=a[i];
    rep1(i,1,n) for(int j: ch[i]) upd(j, li(j,a[i]), 1, a[i]);

    rep1(i,1,q){
        up(qc[i], qx[i]);
        cout << sv(ql[i], qr[i], qk[i]) << "\n";
    }

    return 0;
}