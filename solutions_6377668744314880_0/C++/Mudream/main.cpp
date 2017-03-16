#include <cstdio>
#include <cstdlib>

#include <vector>
#include <cmath>

#include <set>
#include <algorithm>

using namespace std;

int sgn(int a){ return a<0 ? -1 : a>0;}

class pt{
public:
    int x, y;
    pt(int _x = 0, int _y = 0):x(_x), y(_y){}
};

bool operator==(const pt& a, const pt& b){return sgn(a.x-b.x) == 0 and sgn(a.y-b.y) == 0;}
pt operator-(const pt& a, const pt& b){return pt(a.x - b.x, a.y - b.y);}
pt operator+(const pt& a, const pt& b){return pt(a.x + b.x, a.y + b.y);}
int operator^(const pt& a, const pt& b){return a.x*b.y - a.y*b.x;}
bool operator<(const pt& a, const pt& b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

struct cpbyx{bool operator()(pt a, pt b){return a.x == b.x ? a.y < b.y : a.x < b.x;}};
vector<pt> ConvexHull(vector<pt> inp){
    vector<pt> bt_ret, tp_ret;
    sort(inp.begin(), inp.end(), cpbyx());
    auto it = unique(inp.begin(), inp.end());
    inp.resize(distance(inp.begin(), it));
    for(int lx = 0;lx < inp.size();lx++){
        pt v = inp[lx];
        for(int ly = (int)bt_ret.size()-1;ly>=1;ly--){
            if(sgn((bt_ret[ly]-bt_ret[ly-1])^(v-bt_ret[ly])) < 0){
                bt_ret.pop_back();
            }else
                break;
        }
        bt_ret.push_back(v);
    }
    for(int lx = (int)inp.size()-1;lx>=0;lx--){
        pt v = inp[lx];
        for(int ly = ((int)tp_ret.size())-1;ly>=1;ly--)
            if(sgn((tp_ret[ly]-tp_ret[ly-1])^(v-tp_ret[ly])) < 0)
                tp_ret.pop_back();
            else
                break;
        tp_ret.push_back(v);
    }
    
    vector<pt> ret;
    for(int lx = 0;lx < bt_ret.size();lx++)
        ret.push_back(bt_ret[lx]);
    for(int lx = 0;lx < tp_ret.size();lx++)
        ret.push_back(tp_ret[lx]);
    return ret;
}

set<pt> Vec2Set(vector<pt> inp){
    set<pt> ret;
    for(auto it : inp) 
        ret.insert(it);
    return ret;
}

set<pt> tab[1<<15]; int cnt[1<<15];

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int n; scanf("%d", &n);
        pt ps[100];
        for(int lx = 0;lx < n;lx++)
            scanf("%d %d", &ps[lx].x, &ps[lx].y);

        for(int sts = 0;sts < (1<<n);sts++){
            vector<pt> prc;
            cnt[sts] = 0;
            for(int lx = 0;lx < n;lx++)
                if(sts&(1<<lx)){
                    prc.push_back(ps[lx]);
                    cnt[sts]++;
                }
            tab[sts] = Vec2Set(ConvexHull(prc));
        }
        
        printf("Case #%d:\n", lt);
        for(int lx = 0;lx < n;lx++){
            int mm = 100;
            for(int ls = 0;ls < (1<<n);ls++)
                if(tab[ls].count(ps[lx]))
                    mm = min(mm, n-cnt[ls]);
            printf("%d\n", mm);
        }
    }
    return 0;
}

