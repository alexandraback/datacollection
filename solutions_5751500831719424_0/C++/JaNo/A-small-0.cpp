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
#define ForEach(it, i) for(typeof i.begin() it = i.begin(); it!=i.end(); ++it)
#define INF 1023456789
#define eps 1e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
char str[147][147];
int pos[147], cnt[147];
int myabs(int x) { return (x<0)?-x:x; }

int extra(){
    scanf("%d",&n);
    For(i, n) {
        scanf("%s", str[i]);
        pos[i] = 0;
    }

    int moves = 0;
    while(true){
        char f = str[0][pos[0]];
        For(i, n){
            if (str[i][pos[i]]!=f) return INF;
            cnt[i] = 1;
            while(str[i][pos[i]]>0 && str[i][pos[i]]==f) {
                cnt[i]++;
                pos[i]++;
            }
        }
        if (f==0) break;
        sort(cnt, cnt+n);
        int med = cnt[n/2];
        For(i, n)
            moves+=myabs(cnt[i] - med);    
    }
    return moves;
}

int main(){
    int T;
    scanf("%d",&T);
    For(i,T){
        printf("Case #%d: ",i+1);
        int p = extra();
        if (p<INF) printf("%d\n", p);
        else printf("Fegla Won\n");
    }
}
