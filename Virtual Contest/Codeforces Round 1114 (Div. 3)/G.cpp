#include <bits/stdc++.h>
using namespace std;
/*
Author - Player__
*/
typedef long long ll;
#define  fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void slv(){// hard upsolve on G 
    //figuring it out..
int n;cin>>n;
vector<ll> a(n+1);

for(int i=1;i<=n;i++) cin>>a[i];

vector<int > p(n+1);

     for(int i=2;i<=n;i++){
    cin>>p[i];
}
vector<priority_queue<ll, vector<ll> , greater<ll>>> pq(n+1);

vector<ll> av;

    for(int i=n;i>=1;i--){
    if(pq[i].empty()){
        pq[i].push(a[i]);
    }else{
        ll x=pq[i].top();
        pq[i].pop();
        pq[i].push(max(x,a[i]));
         av.push_back(min(x,a[i]));
    }

    if(i>1){
        int par=p[i];
        if(pq[par].size() <pq[i].size()) swap(pq[par],pq[i]);

        while(!pq[i].empty()){
            pq[par].push(pq[i].top());
            pq[i].pop();
        }
    }
}
int l=pq[1].size();
ll sum=0;
while(!pq[1].empty()){
    sum+=pq[1].top();
    pq[1].pop();
}
vector<ll> ans(n+1,-1);
ans[l]=sum;
sort(av.rbegin(),av.rend());
for(int i=0;i<av.size();i++){
    sum+=av[i];
    ans[l+i+1]=sum;
}
for(int k=1;k<=n;k++){
    cout<<ans[k]<<" \n"[k==n];
}



}


int main (){
    fast_io
int t;cin>>t;
 while(t--){
slv();

   }
return 0;
}