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

std::pair<int, vector<string>> sol(int r, int c, int n){	
    
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
    
    vector<string> res(r,string(c,'?'));
    
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
        
        
        if (tmp < mi) {
            mi = tmp;
            FOR(i,0,r-1) FOR(j,0,c-1) {
                res[i][j] = (flag[i][j] ? '*' : '.');
            }
        }
        
        
        FOR(i,0,L-1) if (perm[i] == 1) {
            flag[points[i].x][points[i].y] = false;
        }
        
    } while (next_permutation(perm.begin(), perm.end()));
    
    return {mi, res};
}

int way1(int r, int c, int n) {
    int res = 0;
    if (n <= (r*c) / 2) return 0;
    n -= (r*c) / 2;
    
    if (n <= 4) return n*2;
    n -= 4;
    res += 4*2;
    
    if (n <= r+c-6) return res + n*3;
    res += (r+c-6)*3;
    n -= r+c-6;
    
    return res + n*4;
}

int way2(int r, int c, int n) {
    int res = 0;
    if (n <= (r*c+1) / 2) return 0;
    n -= (r*c+1) / 2;
    
    if (n <= r+c-2) return res + n*3;
    res += (r+c-2)*3;
    n -= r+c-2;
    
    return res + n*4;
}

int sol2(int r, int c, int n)
{
    int res = 0;
    
    if (r==1 || c == 1) {
        if (r > c) swap(r,c); // r == 1
        
        if (c % 2 == 0) {
            if (n <= c / 2) return 0;
            if (n == c/2 + 1) return 1;
            return 1 + (n-c/2-1)*2;
        } else {
            if (n <= (c+1)/2) return 0;
            return (n - (c+1)/2)*2;
        }
        
    }
    
    if ((r*c) % 2 == 0) {
        if (n <= r*c / 2) return 0;
        n -= r*c / 2;
        
        if (n <= 2) return res + n * 2;
        res += 2*2;
        n -= 2;
        
        if (n <= r+c-4) return res + n*3;
        n -= (r+c-4);
        res += (r+c-4)*3;
        
        return res + n*4;
    } else {
        return min(way1(r,c,n), way2(r,c,n));
    }
}
int main()
{
    int T;
    int r,c,n;
	init();
    cin >> T;
    FOR(t,1,T) {
        cin >> r >> c >> n;
        //cout << "Case #" << t << ": " << sol().first << endl;
        cout << "Case #" << t << ": " << sol2(r,c,n) << endl;
    }
    

    
    // cin >> r >> c;
    
    // FOR(i,0,r*c) {
        // auto p = sol(r,c,i);
        // cout << "n=" << i << " mi=" << p.first << endl;
        // FOR(j,0,r-1) cout << p.second[j] << endl;
    // }
    
    // FOR(R,1,5) FOR(C,1,5) FOR(N,0,R*C) {
        // auto s1 = sol(R,C,N).first;
        // auto s2 = sol2(R,C,N);
        // cout << R << " " << C << " " << N << ":" << s1 << " " << s2 << endl;
        // if (s1 != s2) cout << "###" << endl;
    // }
    
	return 0;
}