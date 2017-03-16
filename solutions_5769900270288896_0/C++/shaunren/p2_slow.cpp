#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdint.h>
using namespace std;

int n,r,c;
bool occ[10001];
int dist[10001];
int best;

#define COORD(y,x) ((x)+(y)*c)

void search(int cur=1, int crd=1)
{
    if (cur>=n) {
        int uh=0;
        for (int y=0;y<r;y++)
            for (int x=0;x<c;x++) {
                if (!occ[COORD(y,x)]) continue;
                if (y<r-1 && occ[COORD(y+1,x)]) uh++;
                if (x<c-1 && occ[COORD(y,x+1)]) uh++;
            }
        best = min(best,uh);
        return;
    }
    for (int i=crd;i+(n-cur)<=r*c;i++) {
        occ[i] = true;
        search(cur+1,i+1);
        if (best<=0) return;
        occ[i] = false;
    }
}

__attribute__((optimize("-O3")))
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);

    int tcas;

    cin >> tcas;
    
     for (int cas=1;cas<=tcas;cas++) {
        cin >> r >> c >> n;
        int uh=0;
        if (n<2) {
            cout << "Case #"<<cas << ": 0\n";
            continue;
        }
        for (int i=1;i<r*c-1;i++) occ[i] = false;
        occ[0] = true;
        best = 1000000000;
        search();
        cout << "Case #" << cas << ": " << best << endl;
     }
    
    return 0;
}
