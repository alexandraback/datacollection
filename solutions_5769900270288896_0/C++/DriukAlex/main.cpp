#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>
#include <sstream>
#include <stdarg.h>
#include <fstream>

using namespace std;

int mas[16][16];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


void solve(int t) {
    int R,C,N;
    cin>>R>>C>>N;
    int mini=1000000000;
    for (int i=0;i<(1<<(R*C));i++) {
        int num=0;
        for (int j=0;j<R;j++) {
            for (int k=0;k<C;k++) {
                int now = j*C+k;
                if (i&(1<<now)) {
                    mas[j][k]=1;
                    num++;
                } else {
                    mas[j][k]=0;
                }
            }
        }
        if (num!=N)
            continue;
        int curmin=0;
        for (int j=0;j<R;j++) {
            for (int k=0;k<C;k++) {
                if (mas[j][k]==0)
                    continue;
                for (int q=0;q<4;q++) {
                    int j1=j+dx[q];
                    int k1=k+dy[q];
                    if (j1>=0&&k1>=0&&j1<R&&k1<C) {
                        if (mas[j1][k1]==1)
                            curmin++;
                    }
                }
            }
        }
        mini=min(mini,curmin);
    }
    printf("Case #%d: %d\n",t,mini/2);
}

int main() {
    freopen("in.in","r",stdin);    
    freopen("out.out","w",stdout);    
    int T;
    cin>>T;
    for (int i=0;i<T;i++)
        solve(i+1);
    return 0;
}