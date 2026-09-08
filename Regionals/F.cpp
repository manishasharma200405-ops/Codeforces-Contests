#include <bits/stdc++.h>

using namespace std;

/*
Player__
*/
typedef long long ll ;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
struct BigInt {
    string s;
    BigInt() : s("0") {}
    BigInt(string str) { s = str; }
    BigInt(long long v) { s = to_string(v); }

    bool operator==(const BigInt& o) const {
        return s == o.s;
    }

    BigInt operator*(const BigInt& o) const {
        if (s == "0" || o.s == "0") return BigInt("0");
        int n = s.length(), m = o.s.length();
        vector<int> res(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s[i] - '0') * (o.s[j] - '0');
                int sum = mul + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        string rs = "";
        int idx = 0;
        while (idx < res.size() && res[idx] == 0) idx++;
        while (idx < res.size()) rs.push_back(res[idx++] + '0');
        return BigInt(rs.empty() ? "0" : rs);
    }
};
int main(){
    fast_io;

string s ;cin>>s;
string c;cin>>c;
//split s in such a / b=c
// c x b=a
//digit length formula 

int n=s.size();
int lc=c.size();
vector<int> can;
if((n-lc+1) %2==0){
    can.push_back((n-lc+1) /2);
}
if((n-lc) %2==0){
    can.push_back((n-lc)/2);
}
BigInt C(c);
for(int lb: can){
    int la=n-lb;
    if(lb<=0 || la<=0) continue;
    string a =s.substr(0,la);
   string b=s.substr(la);
 BigInt A(a);
 BigInt B(b);

 if(A ==B *C){
    cout<<a<<"\n";
    cout<<b<<"\n";
    return 0;
 }

}
}