#include <cstdio>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;

#define D(x...) fprintf(stderr,x)
#define D(x...)

#define x first
#define y second

typedef long double real;
typedef pair<real,real> point;

const real EPS = 1e-9;
const int MAX_N = 3005;

int N;
point points[MAX_N];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        printf("Case #%d:\n",z);
        scanf("%d",&N);

        for(int i=0;i<N;i++) {
            scanf("%Lf %Lf",&points[i].x,&points[i].y);
        }

        for(int i=0;i<N;i++) {
            vector<real> angle;
            // fix i
            point p = points[i];

            // find angles
            for(int j=0;j<N;j++) {
                if(i != j) {
                    angle.push_back(atan2(points[j].y-p.y, points[j].x-p.x));
                }
            }

            sort(angle.begin(), angle.end());

            D("* i=%d: p:(%Lf,%Lf), angle:",i,p.x,p.y);
            for(int i=0;i<angle.size();i++) {
                D(" %Lf",angle[i]);
            }
            D("\n");

            vector<real> pos;
            pos.push_back(-M_PI);
            for(int i=0;i<angle.size();i++) {
                if(angle[i] <= 0.0) {
                    pos.push_back(angle[i]);
                }
            }
            pos.push_back(0.0);

            int best = 0;
            for(int i=0;i<pos.size();i++) {
                real r = pos[i];
                vector<real>::iterator a = lower_bound(angle.begin(), angle.end(), r-EPS);
                vector<real>::iterator b = upper_bound(angle.begin(), angle.end(), r+M_PI+EPS);
                D("+r=%Lf: a=%d, b=%d\n",r,(int)(a-angle.begin()), (int)(b-angle.begin()));
                int here = (int)(b-a);
                if(a <= b) {
                    best = max(best, here);
                }

                a = lower_bound(angle.begin(), angle.end(), r+EPS);
                b = upper_bound(angle.begin(), angle.end(), r+M_PI-EPS);
                D("-r=%Lf: a=%d, b=%d\n",r,(int)(a-angle.begin()), (int)(b-angle.begin()));
                if(a <= b) {
                    here = N-1 - (int)(b-a);
                    best = max(best, here);
                }
            }
            best++;
            printf("%d\n",N-best);
        }
    }

    return 0;
}
