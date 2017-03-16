//Fruit of Light
//FoL CC
//Apple Strawberry

#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<cstring>

using namespace std;

#define For(i, n) for(int i = 0; i<(n); ++i)
#define INF 1023456789
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int extra(){
    int r,s,n;
    scanf("%d%d%d", &r,&s,&n);
    int sq = r*s;
    int bad = 1000;
    For(mask, (1<<sq)) {
        int black = 0;
        int sad = 0;
        For(i, r) For(j, s) {
            int p = i*s+j;
            int isblack = bool(mask & (1<<p));
            black += isblack;
            p = i*s+j+1;
            if (isblack && j+1<s) sad += bool(mask & (1<<p));
            p = (i+1)*s+j;
            if (isblack && i+1<r) sad += bool(mask & (1<<p));
        }
        if (black==n) bad = min(bad, sad);
    }
    printf("%d\n", bad);
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: ",i+1);
        extra();
    }
}
