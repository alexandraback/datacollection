#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define y1 adjf

vector<int> cnt(26, 0);
int n, t;
set<pair<int, int>, greater<pair<int, int> > > curr;
int tot;

void solve(int testc){
    printf("Case #%d: ", testc);
    scanf("%d", &n);
    cnt.asg(26, 0);
    curr.clear();
    tot = 0;
    F(i, 0, n){
        scanf("%d", &cnt[i]);
        curr.ins(mk(cnt[i], i));
        tot += cnt[i];
    }
    int pleft = n;
    while(pleft > 2 && !curr.empty()){
        pair<int, int> gm = *(curr.begin());
        curr.era(curr.begin());
        printf("%c ", 'A' + gm.Y);
        cnt[gm.Y]--;
        gm.X--;
        if(gm.X == 0){
            pleft--;
        }
        else{
            curr.ins(mk(gm.X, gm.Y));
        }
    }
    if(pleft == 2){
        pair<int, int> fp = *(curr.begin());
        curr.era(curr.begin());
        pair<int, int> sp = *(curr.begin());
        curr.era(curr.begin());
        while(fp.X > sp.X){
            printf("%c ", 'A' + fp.Y);
            fp.X--;
        }
        F(i, 0, fp.X){
            printf("%c%c ", 'A' + fp.Y, 'A' + sp.Y);
        }
    }
    printf("\n");
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &t);
    F(i, 0, t){
        solve(i + 1);
    }
    ret 0;
}
