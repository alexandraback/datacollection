#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <ctime>
#include <memory.h>

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,Be,En) for(int (i)=(Be);(i)<=(En);++(i))
#define DFOR(i,Be,En) for(int (i)=(Be);(i)>=(En);--(i))
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a,0,sizeof(a))

#define LL  long long
#define VI  vector<int>
#define PAR pair<int ,int> 

using namespace std;
void __never(int a){printf("\nOPS %d", a);}
void __die(int a){printf("%d",(a*a)/(a+a));}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();__die(0);}}



int r,c,n;

struct Point {int x,y;};

int nums[32][32];
bool flag[32][32];

int dx[] = {0,1};
int dy[] = {1,0};

void init()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
}

int sol(){	
    
    vector<Point> points;
    FOR(i,0,r-1) FOR(j,0,c-1) {
        nums[i][j] = points.size();
        points.push_back(Point{i,j});
    }
    CLR(flag);
    int L = r*c;
    vector<int> perm(L, 0);
    
    FOR(i,L-n,L-1) {
        perm[i] = 1;
    }
    
    int mi = L*4;
    
    do {
        FOR(i,0,L-1) if (perm[i] == 1) {
            flag[points[i].x][points[i].y] = true;
        }
        int tmp = 0;
        FOR(i,0,r-1) FOR(j,0,c-1) {
            if (!flag[i][j]) continue;
            FOR(k,0,1) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < r && y < c && flag[x][y]) ++tmp;
            }
        }
        
        FOR(i,0,L-1) if (perm[i] == 1) {
            flag[points[i].x][points[i].y] = false;
        }
        
        if (tmp < mi) mi = tmp;
        
    } while (next_permutation(perm.begin(), perm.end()));
    
    return mi;
}
int main()
{
    int T;
	init();
    cin >> T;
    FOR(t,1,T) {
        cin >> r >> c >> n;
        cout << "Case #" << t << ": " << sol() << endl;
    }
	return 0;
}