//Atcoder Heuristic Contest 068
// kenway_Connor
#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define INLINE __attribute__((always_inline)) inline

const double TL = 1.6;
const int CAP = 100000;
#ifdef LOCAL
    #define DBG(x) cerr << #x << " = " << (x) << endl
#else
    #define DBG(x)
#endif


static ull rng_state = 88172645463325252ULL;
INLINE ull rnd(){ rng_state^=rng_state<<13; rng_state^=rng_state>>7; rng_state^=rng_state<<17; return rng_state; }
INLINE int rnd(int n){ return rnd()%n; }
INLINE double rndd(){ return (rnd()>>11)*(1.0/9007199254740992.0); }

static chrono::steady_clock::time_point T0;
INLINE double elapsed(){ return chrono::duration<double>(chrono::steady_clock::now()-T0).count(); }

// variables
int N;
char V[20][20], H[20][20];

long long iter_cnt = 0;
long long valid = 0;
double best_s = 1e18;

int a[20][20], pr[400], pc[400];
bool fx[20][20];
int dep[20][20], pd[20][20];
pair<int,int> par[20][20];
// struct for grid NxN 
struct Op{ 
    char d;
     int r,c,h,w;
     };
vector<Op> ops, betr_ops;
bool to_val = false;

INLINE bool cR(int i,int j){ return j+1<N && V[i][j]=='0'; }
INLINE bool cD(int i,int j){ return i+1<N && H[i][j]=='0'; }

INLINE void sw(int r1,int c1,int r2,int c2){
    if(r1==r2) ops.push_back({'H',r1,min(c1,c2),1,2});
    else ops.push_back({'V',min(r1,r2),c1,2,1});
    swap(a[r1][c1],a[r2][c2]);
    pr[a[r1][c1]]=r1;
     pc[a[r1][c1]]=c1;
    pr[a[r2][c2]]=r2; 
    pc[a[r2][c2]]=c2;
}

bool routeFix(int ti,int tj){
    int need=ti*N+tj, cr=pr[need], cc=pc[need];
    if(cr==ti&&cc==tj){ fx[ti][tj]=true; return true; }
    memset(pd,-1,sizeof(pd));
    queue<pair<int,int>> bq; pd[cr][cc]=0; bq.push({cr,cc});
    while(!bq.empty()){
        auto[i,j]=bq.front(); bq.pop();
        if(i==ti&&j==tj) break;
        auto tm=[&](int ni,int nj){
            if(ni<0||ni>=N||nj<0||nj>=N) return;
            if(fx[ni][nj]&&!(ni==ti&&nj==tj)) return;
            if(pd[ni][nj]!=-1) return;
            pd[ni][nj]=pd[i][j]+1;
             par[ni][nj]={i,j}; 
             bq.push({ni,nj});
        };
        if(cR(i,j)) tm(i,j+1);
        if(j>0&&cR(i,j-1)) tm(i,j-1);
        if(cD(i,j)) tm(i+1,j);
        if(i>0&&cD(i-1,j)) tm(i-1,j);
    }
    vector<pair<int,int>> path;
    int ci=ti,cj=tj;
    if(pd[ti][tj]==-1) return false; 
    while(!(ci==cr&&cj==cc)){ path.push_back({ci,cj}); 
    auto[pi,pj]=par[ci][cj];
     ci=pi;
      cj=pj;
       }
    path.push_back({cr,cc});
    reverse(path.begin(),path.end());
    REP(k,(int)path.size()-1){
        sw(path[k].first,path[k].second,path[k+1].first,path[k+1].second);
        if((int)ops.size() > CAP) return false; 
    }
    fx[ti][tj]=true;
    return true;
}

int a0[20][20]; 

void reset(){
    REP(i,N) REP(j,N) a[i][j] = a0[i][j];
    REP(i,N) REP(j,N){ pr[a[i][j]]=i; pc[a[i][j]]=j; }
    memset(fx,0,sizeof(fx));
    ops.clear();
}

bool build(int rootR, int rootC){
    memset(dep,-1,sizeof(dep));
    queue<pair<int,int>> q; dep[rootR][rootC]=0; q.push({rootR,rootC});
    while(!q.empty()){
        auto[i,j]=q.front(); q.pop();
        if(cR(i,j)&&dep[i][j+1]==-1){ dep[i][j+1]=dep[i][j]+1;
         q.push({i,j+1});
          }
        if(j>0&&cR(i,j-1)&&dep[i][j-1]==-1){
             dep[i][j-1]=dep[i][j]+1;
              q.push({i,j-1}); }
        if(cD(i,j)&&dep[i+1][j]==-1){
             dep[i+1][j]=dep[i][j]+1; 
             q.push({i+1,j}); 
             }
        if(i>0&&cD(i-1,j)&&dep[i-1][j]==-1){ 
            dep[i-1][j]=dep[i][j]+1; 
            q.push({i-1,j});
             }
    }
    vector<tuple<int,int,int,int>> ord;
    REP(i,N) REP(j,N) ord.push_back({dep[i][j], rnd(1000000), i, j}); 
    sort(ord.begin(),ord.end(),[](auto&x,auto&y){ return get<0>(x)>get<0>(y); });
    for(auto&[d,rk,ti,tj]:ord){
        if(!routeFix(ti,tj)) return false;
        if((int)ops.size() > CAP) return false;
    }
    return true;
}

INLINE bool isCur(){
    REP(i,N) REP(j,N) if(a[i][j] != i*N+j) return false;
    return true;
}

void improve(){
    
    if((int)ops.size() <= CAP && isCur()){
        betr_ops = ops;
        to_val = true;
    }
    while(elapsed() < TL){
        iter_cnt++;
        int rr = rnd(N), rc = rnd(N);
        reset();
        build(rr, rc);
        if((int)ops.size() <= CAP && isCur() && (!to_val || ops.size() < betr_ops.size())){
            betr_ops = ops;
            to_val = true;
            valid++;
        }
    }
}

int main(){
    T0 = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    REP(i,N) REP(j,N) cin >> a[i][j];
    REP(i,N) REP(j,N) a0[i][j] = a[i][j];
    REP(i,N){ string s; cin>>s; REP(j,N-1) V[i][j]=s[j]; }
    REP(i,N-1){ string s; cin>>s; REP(j,N) H[i][j]=s[j]; }
    REP(i,N) REP(j,N){ pr[a[i][j]]=i; pc[a[i][j]]=j; }

    build(0,0);
    DBG(isCur());
    improve();

   
    for(int rr=0; !to_val && rr<N; ++rr){
        for(int rc=0; !to_val && rc<N; ++rc){
            reset();
            build(rr, rc);
            if((int)ops.size() <= CAP && isCur()){
                betr_ops = ops;
                to_val = true;
            }
        }
    }

   
    if(!to_val){
        betr_ops.clear();
    }

   // cout << ops.size() << "\n";
  // cerr << "opcount=" << betr_ops.size() << "\n";
   cout << betr_ops.size() << "\n";
    for(auto&o:betr_ops) cout << o.d<<" "<<o.r<<" "<<o.c<<" "<<o.h<<" "<<o.w<<"\n";

 
    DBG(iter_cnt);
    DBG(elapsed());
    return 0;
}