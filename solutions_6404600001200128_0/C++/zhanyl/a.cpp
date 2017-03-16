#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const int maxn=1005;

int n;
int f[maxn];

int solve1(){
    int ans=0;
    for(int i=1;i<n;i++)
        if(f[i]<f[i-1])ans+=f[i-1]-f[i];
    return ans;
}

int solve2(){
    int v=0;
    for(int i=1;i<n;i++)
        v=max(v,f[i-1]-f[i]);
    int ans=0;
    for(int i=0;i<n-1;i++)
        ans+=min(v,f[i]);
    return ans;
}

int main(){
    string str_in,str_out;
    cin>>str_in>>str_out;
    freopen(str_in.c_str(),"r",stdin);
    freopen(str_out.c_str(),"w",stdout);
    int T;
    scanf("%d",&T);
    for(int Cas=1;Cas<=T;Cas++){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&f[i]);
        printf("Case #%d: %d %d\n",Cas,solve1(),solve2());
    }
    return 0;
}
