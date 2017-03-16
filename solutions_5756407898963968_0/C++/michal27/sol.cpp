#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

void solve(int num) {
    int k1,k2;
    scanf("%d",&k1);
    int x;
    set<int> S;
    For(i,4) For(j,4) {
        scanf("%d",&x);
        if(i==k1-1) S.insert(x);
    }
    vector<int> V;
    scanf("%d",&k2);
    For(i,4) For(j,4) {
        scanf("%d",&x);
        if(i!=k2-1) continue;
        if(S.find(x)!=S.end()) V.push_back(x);
    }
    printf("Case #%d: ",num);
    if(V.size()==0) printf("Volunteer cheated!\n");
    else if(V.size()==1) printf("%d\n",V[0]);
    else printf("Bad magician!\n");
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
return 0;
}
