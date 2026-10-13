#include <bits/stdc++.h>
using namespace std;


#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
vector<string>s;
int n;int k;
bool cln(string &a){return a[0]!='0';}

bool cSel(int i,int j){
    if(s[i].size()!=s[j].size())return s[i].size()>s[j].size();
    return s[i]>s[j];
}

bool cArr(const string &a,const string &b){return a+b>b+a;}

string strp(string r){
    int p=0;
    while(p+1<(int)r.size()&&r[p]=='0')p++;
    return r.substr(p);
}

string arr(vector<string> v){
    sort(all(v),cArr);
    string r;
    for(auto &x:v)r+=x;
    return strp(r);
}

string cdA(bool &f){
    vector<int> id(n);
    iota(all(id),0);
    sort(all(id),cSel);
    vector<int> ch(id.begin(),id.begin()+k);
    bool hc=false;
    for(int i:ch)if(cln(s[i])){hc=true;break;}
    if(!hc){
        int bc=-1;
        rep(i,n){
            if(!cln(s[i]))continue;
            if(bc==-1||cSel(i,bc))bc=i;
        }
        if(bc==-1){f=false;return "";}
        ch.pop_back();
        ch.pb(bc);
    }
    f=true;
    vector<string> v;
    for(int i:ch)v.pb(s[i]);
    return arr(v);
}

string cdB(bool &f){
    vector<int> d;
    rep(i,n)if(!cln(s[i]))d.pb(i);
    if((int)d.size()<k){f=false;return "";}
    sort(all(d),cSel);
    vector<string> v;
    rep(i,k)v.pb(s[d[i]]);
    f=true;
    return arr(v);
}

bool btr(const string &x,const string &y){
    if(x.size()!=y.size())return x.size()>y.size();
    return x>=y;
}

int main (){
    fast_io
cin>>n;
cin>>k;

 s.resize(n);
    rep(i,n){
        cin>>s[i];
    }

    bool fa,fb;
    string a=cdA(fa);
    string b=cdB(fb);
    string ans;
    if(fa&&fb)ans=btr(a,b)?a:b;
    else if(fa)ans=a;
    else if(fb)ans=b;
    else ans="0";
    cout<<ans<<"\n";

    return 0;

}
