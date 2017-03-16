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

bool mas[10000][10000];

void solve(int t) {
    int R,C,N;
    cin>>R>>C>>N;
    if (N<=(R*C+1)/2) {
        printf("Case #%d: 0\n",t);
        return;
    }
    int N1=N-(R*C+1)/2;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if ((i+j)%2 == 0) {
                mas[i][j]=true;
            }
        }
    }
    int res1=0;
    if (min(R,C)==1) {
        int ones1=(max(R,C)-1)%2;
        res1+=min(ones1,N1);
        N1-=min(ones1,N1);
        res1+=N1*2;
    } else {
        int twos1=0;
        if (R%2 == 0)
            twos1++;
        if (C%2 == 0)
            twos1++;
        if ((R+C)%2 != 0)
            twos1++;
        int threes1 = R+C-2-twos1;
        res1+=min(twos1,N1)*2;
        N1-=min(twos1,N1);
        res1+=min(threes1,N1)*3;
        N1-=min(threes1,N1);
        res1+=N1*4;
    }
    int N2=N-((R*C+1)/2-1);
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if ((i+j)%2 != 0) {
                mas[i][j]=true;
            }
        }
    }
    int res2=0;
    if (min(R,C)==1) {
        int ones2=1+(max(R,C))%2;
        res2+=min(ones2,N2);
        N2-=min(ones2,N2);
        res2+=N2*2;
    } else {
        int twos2=1;
        if (R%2 != 0)
            twos2++;
        if (C%2 != 0)
            twos2++;
        if ((R+C)%2 == 0)
            twos2++;
        int threes2 = R+C-2-twos2;
        res2+=min(twos2,N2)*2;
        N2-=min(twos2,N2);
        res2+=min(threes2,N2)*3;
        N2-=min(threes2,N2);
        res2+=N2*4;
    }
    printf("Case #%d: %d\n",t,min(res1,res2));
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