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

int oneway(int r, int c, int n){
    int sq = r*c;
    int zero = sq-sq/2;
    int one = 0;
    int two = 0;
    if (sq%2==0) two = 2;
    if (min(r,c)==1) {
        two = sq/2;
        if (sq%2==0) {two--; one++;}
    }
    int inside = max(0,((r-2)*(c-2))/2);
    int bound = sq/2 - inside;
    int three = bound-two-one;
    int four = inside;
   
    int bad = 0;
    n -= zero;
    bad += max(0, min(n, one)); n-=one;
    bad += max(0, min(n, two))*2; n-=two;
    bad += max(0, min(n, three))*3; n-=three;
    bad += max(0, min(n, four))*4;
    return bad;
}
int secondway(int r, int c, int n){
    if (min(r,c)==1) return INF;
    int sq = r*c;
    int zero = sq/2;
    int one = 0;
    int two = 0;
    if (sq%2==0) two = 2;
    else two = 4;
    int inside = max(0,(r-2)*(c-2) - ((r-2)*(c-2))/2);
    int bound = (sq - sq/2) - inside;
    int three = bound-two-one;
    int four = inside;
   
    int bad = 0;
    n -= zero;
    bad += max(0, min(n, one)); n-=one;
    bad += max(0, min(n, two))*2; n-=two;
    bad += max(0, min(n, three))*3; n-=three;
    bad += max(0, min(n, four))*4;
    return bad;
}

int extra(){
    int r,c,n;
    scanf("%d%d%d", &r,&c,&n);
    printf("%d\n", min(oneway(r,c,n), secondway(r,c,n)));
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: ",i+1);
        extra();
    }
}
