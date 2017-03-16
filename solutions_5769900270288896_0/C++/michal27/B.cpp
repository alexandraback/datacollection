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

int A[20][20];

void solve(int p1) {
    int r,c,n;
    scanf("%d %d %d",&r,&c,&n);
    int res=4*r*c;
    For(i,1<<(r*c)) {
        int pocet=0;
        For(j,r*c) if(i&(1<<j)) pocet++;
        if(pocet != n) continue;
        For(j,r+1) For(k,c+1) A[j][k]=0;
        For(j,r*c) if(i&(1<<j)) A[j/c][j%c]=1;
        //For(j,r) {For(k,c) printf("%d",A[j][k]); printf("\n");}
        int poc=0;
        For(j,r) For(k,c) {
            if(A[j][k]==1 && A[j+1][k]==1) poc++;
            if(A[j][k]==1 && A[j][k+1]==1) poc++;
        }
        res=min(res,poc);
    }
    printf("Case #%d: %d\n",p1,res);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
}
