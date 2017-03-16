#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int cnt[17];
vector<int> cnt2[3];
int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d: ", ti);
        for (int i = 1; i <= 16; i++) {
            cnt[i] = 0;
        }
        for (int i = 0; i <= 2; i++) {
            cnt2[i].clear();
        }
        for (int i = 0; i < 2; i++) {
            int r;
            scanf("%d", &r);
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    int x;
                    scanf("%d", &x);
                    if (j + 1 == r) {
                        cnt[x]++;
                    }
                }
            }
        }        
        for (int i = 1; i <= 16; i++) {
            cnt2[cnt[i]].pb(i);
        }
        if (sz(cnt2[2]) == 1) {
            printf("%d\n", cnt2[2][0]);
        } else 
        if (sz(cnt2[2]) > 1) {
            printf("Bad magician!\n");
        } else {
            printf("Volunteer cheated!\n");
        }
    }
    return 0;
}
