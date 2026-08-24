#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm> // Explicitly required for std::sort
#include <utility> 
#include "molecules.h"

 std::vector<int> find_subset(int l, int u, std::vector<int> w){int n=static_cast<int>(w.size());
   std::vector<std::pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        p[i]={w[i],i};//shortcut for pair creation

    }

  std::sort(p.begin(),p.end());
    long long curr_sum=0;//two pointer with sliding window 
int lf=0;
for(int i=0;i<n;i++){
    curr_sum+=p[i].first;
    while(curr_sum>u && lf<=i){
        curr_sum-=p[lf].first;
lf++;
    }
    if(curr_sum>=l && curr_sum<=u){
        std::vector<int> res;
        for(int j=lf;j<=i;j++){
            res.push_back(p[j].second);

        }return res;
    }
}  
    return {};

    
}