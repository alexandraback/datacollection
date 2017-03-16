#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <list>
#include <stack>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <functional>

#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef  long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;
typedef priority_queue<int> PQI;
const int Mod = 1e9 + 7;
inline LL FIX(LL a) {return (a % Mod + Mod) % Mod;}
#define MP(x,y) make_pair(x,y)
#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define take(x,y) (((x)>>(y)) & 1ll)
#define mv(n) (1<<(n))
#define what_is(x) cerr << #x << " is " << x << endl;
#define eb emplace_back
#define pb push_back
#define UNQ(x) (sort(begin(x),end(x)),x.erase(unique(begin(x),end(x)),end(x)))

const double eps=1e-10;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    bool operator==(const Point& rhs)const
    {
        return dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)==0;
    }
    bool operator<(const Point& rhs)const
    {
        return dcmp(x-rhs.x)<0 || (dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)<0);
    }
};
typedef Point Vector;
Vector operator-(Point A,Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
Point pts[20];
int ret[20];
vector<int>cur;
int ch[20];
int gao(vector<int> & E) {
    sort(begin(E),end(E),[](const int &x,const int &y) {
        return pts[x] < pts[y];
    });
    int n = (int)(unique(begin(E),end(E)) - begin(E));
    if(n < 3) {
        return -1;
    }

    int m = 0;
    for(int i = 0;i < n;i++) {
        while(m > 1 && Cross(pts[ch[m-1]] - pts[ch[m-2]],pts[E[i]] - pts[ch[m-2]]) < 0) m--;
        ch[m++] = E[i];
    }
    int k = m;
    for(int i = n - 2;i >= 0;i--) {
        while(m > k && Cross(pts[ch[m-1]] - pts[ch[m-2]],pts[E[i]] - pts[ch[m-2]]) < 0)m--;
        ch[m++] = E[i];
    }
    if(n > 1) m--;
    cur.clear();
    for(int i = 0;i < m;i++) cur.push_back(ch[i]);
    return m;
}
int main(){
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n;i++) {
            ret[i] = n;
        }
        for(int i = 0;i < n;i++) {
            double x,y;
            scanf("%lf %lf",&x,&y);
            pts[i].x = x;pts[i].y = y;
        }
        if(n <= 2) {
            printf("Case #%d:\n",++cas);
            for(int i = 0;i < n;i++){
                printf("%d\n",0);
            }
            continue;
        }

        for(int i = 0;i < (1 << n);i++) {
            vector<int>E;
            int cnt = 0;
            for(int j = 0;j < n;j++) {
                if(take(i,j) == 1) {
                    E.push_back(j);
                    cnt++;
                }
            }
            if(E.size() < 3) continue;
            int ch = gao(E);
            if(ch < 3) continue;
            for(int i = 0;i < cur.size();i++) {
                ret[cur[i]] = min(ret[cur[i]],n - cnt);
            }
        }
        printf("Case #%d:\n",++cas);
        for(int i = 0;i < n;i++){
            printf("%d\n",ret[i]);
        }
    }
    return 0;
}



