#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =  20;
const int M = 1 << 15;
const int INF = 0x3f3f3f3f;
struct point{
    ll x, y, v, id;
    point(){};
    point(ll xx, ll yy):x(xx), y(yy){};

    void scan(){
        scanf("%lld%lld", &x, &y);
    }
    ll Xmul(const point &I)const{
        return x * I.y - y * I.x;
    }

    point operator -(const point &I)const{
        return point(x - I.x, y - I.y);
    }

    ll dis(const point &I)const{
        return (x-I.x)*(x-I.x) + (y-I.y)*(y-I.y);
    }
}info[N];
int dig[M], ans[N];
//
bool CmpVonGraham(point a, point b);
class Calgeometry{
    public:
        int temp, i, j;
        point r[N];     //for graham
    public:
        point p[N];
        int size;

        int Graham(){ ///凸包
            int top;

            temp = 0;   p[temp].y = INF;
            for(i = 1; i <= size; i++){
                if(p[i].y < p[temp].y)  temp = i;
                else if(p[i].y == p[temp].y && p[i].x < p[temp].x)  temp = i;
            }
            swap(p[1], p[temp]);
            sort(p + 2, p + size + 1, CmpVonGraham);

            //允许凸包上有在同一条线的点时，倒转最后一条线
            for(i = size - 1; i >= 1; i--){
                if((p[1]-p[i]).Xmul(p[1]-p[size]) != 0ll)    break;
            }
            j = i + 1;  i = size;
            while(i > j){
                swap(p[i], p[j]);   i--;    j++;
            }
            top = 0;
            for(i = 1; i <= 2 && i <= size; i ++){
                r[++top] = p[i];
            }
            while(i <= size){
                while(top >= 2 && (r[top]-r[top-1]).Xmul(p[i]-r[top-1]) < 0ll)   top--;
                ///允许凸包上有在同一条线的点时，改为<0
                r[++top] = p[i];    i ++;
            }
            return top;
        }

}CG;
bool CmpVonGraham(point a, point b){  ///cmp for graham
    if( (CG.p[1]-a).Xmul(CG.p[1]-b) == 0ll) return a.dis(CG.p[1]) < b.dis(CG.p[1]);
    return (CG.p[1]-a).Xmul(CG.p[1]-b) > 0ll;
}
void init(){
    int i, n = 1 <<15;
    for(i = 0; i < n; i++){
        int sum = 0, temp = i;
        while(temp){
            sum += (temp & 1);
            temp >>= 1;
        }
        dig[i] = sum;
    }
}
void build(int n){
    int i, id = 0;
    for(i = 0; n; i++){
        if(n & 1){
            CG.p[++id] = info[i];
        }
        n >>= 1;
    }
    CG.size = id;
}

int main(){

        freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int TC, tc, n, i, j, all, m;
    scanf("%d", &TC);
    init();
    for(tc = 1; tc<= TC; tc++){
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            info[i].scan();
            info[i].id = i;
        }
        all = (1 << n);
        memset(ans, 0x3f, sizeof(ans));
        for(i = 1; i < all; i++){
            build(i);
            m = CG.Graham();

            for(j = 1; j <= m; j++){
                ans[CG.r[j].id] = min(ans[CG.r[j].id], n-dig[i]);
            }
        }
        printf("Case #%d:\n", tc);
        for(i = 0; i < n; i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
