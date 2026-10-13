#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
// used some kruskal style processping 
// also cross qrys udating ......
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int bit = 18;
const int mx = 4000005;

int ch[mx][2];
int cnt[mx];
int nod = 0;

int nw() {
    nod++;
ch[nod][0] = ch[nod][1] = 0;
       
cnt[nod] = 0;
    return nod;
}

int ins(int rt, int val) {
    if (rt == 0) rt = nw();
int cur = rt;
cnt[cur]++;

 for (int b = bit - 1; b >= 0; b--) {
 int bt = (val >> b) & 1;
        if (ch[cur][bt] == 0) ch[cur][bt] = nw();
        cur = ch[cur][bt];
        cnt[cur]++;
    }

    return rt;
}

void era(int rt, int val) {
    int cur = rt;
    cnt[cur]--;

    for (int b = bit - 1; b >= 0; b--) {
 int bt = (val >> b) & 1;
 cur = ch[cur][bt];
 cnt[cur]--;
    }
}

int mrg(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
cnt[a] += cnt[b];
ch[a][0] = mrg(ch[a][0], ch[b][0]);// merging table 
ch[a][1] = mrg(ch[a][1], ch[b][1]);

    return a;
}

int qry(int rt, int x, int m) {
    if (rt == 0 || cnt[rt] == 0) return -1;

    static vector<int> can;
    can.clear();
    can.push_back(rt);

    int res = 0;
    vector<int> nxt;

 for (int b = bit - 1; b >= 0; b--) {
 int xb = (x >> b) & 1;
  int mb = (m >> b) & 1;
 nxt.clear();

 if (mb == 1) { int op = 1 - xb;

for (int c : can) {
    int nd = ch[c][op];
                if (nd != 0 && cnt[nd] > 0)
                    nxt.push_back(nd);
            }

 if (!nxt.empty()) {
     res |= (1 << b);
    can = nxt;
    continue;
            } else {
 vector<int> tmp;

                for (int c : can) {
     int nd = ch[c][xb];
                    if (nd != 0 && cnt[nd] > 0)
                        tmp.push_back(nd);
                }

                can = tmp;
            }
        } else {
            for (int c : can) {
 for (int z = 0; z < 2; z++) {
 int nd = ch[c][z];
                    if (nd != 0 && cnt[nd] > 0)
                        nxt.push_back(nd);
                }
            }

 can = nxt;
        }
  if (can.empty()) break;
    }

    return res;
}
// used prewritten dfs some changed parts .....
void dfs(int nd, int val, int dep, vector<pair<int, int>>& out) {
    if (nd == 0 || cnt[nd] == 0) return;
if (dep == bit) {
out.push_back({val, cnt[nd]});
 return;
    }

    if (ch[nd][0])
        dfs(ch[nd][0], val << 1, dep + 1, out);

    if (ch[nd][1])
        dfs(ch[nd][1], (val << 1) | 1, dep + 1, out);
}

int par[200005];
int tr[200005];
int sz[200005];
bool vis[200005];

int fnd(int x) {
         while (par[x] != x) {
par[x] = par[par[x]];
        x = par[x];
    }

    return x;
}

int main() {
    fast_io

int t;
 cin>>t;

while (t--) {
int n;
cin>>n;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++)
            cin>>a[i];

vector<int> pre(n + 1);
pre[0] = 0;

        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] ^ a[i];

        nod = 0;

        vector<int> ord(n);

        for (int i = 0; i < n; i++)
            ord[i] = i + 1;

        sort(ord.begin(), ord.end(), [&](int x, int y) {
     if (a[x] != a[y])
         return a[x] < a[y];

 return x < y;
        });

 for (int i = 0; i <= n + 1; i++) {
 par[i] = i;
vis[i] = false;
        }

 int ans = 0;

 for (int p : ord) {
 int lt, rt;
 int ls, rs;

 bool lr = false, rr = false;
            int lc = -1, rc = -1;

 if (p > 1 && vis[p - 1]) {
 int r = fnd(p - 1);
lt = tr[r];
ls = sz[r];
lr = true;
 lc = r;
            } else {
 lt = ins(0, pre[p - 1]);
 ls = 1;
            }
 if (p < n && vis[p + 1]) {
 int r = fnd(p + 1);
 rt = tr[r];
 rs = sz[r];
 rr = true;
rc = r;
            }else {
 rt = ins(0, pre[p]);
 rs = 1;
            }

            int m = a[p];
            int sl = pre[p - 1];
            int sr = pre[p];

            vector<pair<int, int>> el;

  if (ls <= rs) {
 dfs(lt, 0, 0, el);

for (auto &q : el) {
      int v = q.first;
  int c = q.second;

    if (v == sl && c == 1) {
     era(rt, sr);

    int res = qry(rt, v, m);

        if (res >= 0)
             ans = max(ans, res);

                        rt = ins(rt, sr);
                    } else {
                        int res = qry(rt, v, m);

                        if (res >= 0)
                            ans = max(ans, res);
                    }
                }
    } else {
     dfs(rt, 0, 0, el);

for (auto &q : el) {
     int v = q.first;
int c = q.second;

 if (v == sr && c == 1) {
 era(lt, sl);

    int res = qry(lt, v, m);

 if (res >= 0)
     ans = max(ans, res);

    lt = ins(lt, sl);
  } else {
     int res = qry(lt, v, m);

     if (res >= 0)
  ans = max(ans, res);
                    }
                }
            }
/*
it is rlly hard i had to use kruskal style small to large trie merge like merging talbe 
quite bad at construciton and now i ahve ot reconstruct here liek wtf !  
but i wannted todo max-cartesian tree thne processing it in psot order . might have been better but i dk tih might work on furthur hidden tt ...... 
*/
            int mr = mrg(lt, rt);
            int ms = ls + rs;

            par[p] = p;

            if (lr)
                par[lc] = p;

            if (rr)
                par[rc] = p;

            tr[p] = mr;
            sz[p] = ms;
            vis[p] = true;
        }

        cout << ans << '\n';
    }

    return 0;
}