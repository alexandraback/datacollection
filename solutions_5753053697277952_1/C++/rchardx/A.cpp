#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;

#define _abs(x) ((x)>0?(x):-(x))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long LL;

const int MAXN = 26+1;

int c[MAXN],N,sum;

void find(int &p,int &q) {
    for (int i = 0; i<N; ++i)
        for (int j = 0; j<N; ++j) {
            if ((i!=j && c[i]>0 && c[j]>0) || (i==j && c[i]>1)) {
                int lim = (sum-2)/2;
                bool flag = 1;
                for (int k = 0; flag && k<N; ++k)
                    if (k!=i && k!=j && c[k]>lim) flag =false;
                if (flag) {
                    p = i;
                    q = j;
                    return;
                }
            }
        }
}

void find(int &p) {
    for (int i = 0; i<N; ++i) {
        if (c[i]>0) {
            int lim = (sum-1)/2;
            bool flag = 1;
            for (int k = 0; flag && k<N; ++k)
                if (k!=i && c[k]>lim) flag =false;
            if (flag) {
                p = i;
                return;
            }
        }
    }
}

int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
  
    int T; cin>>T;
    for (int loop = 1; loop<=T; ++loop) {
        printf("Case #%d:", loop);
        cin>>N;
        sum = 0;
        for (int i = 0; i<N; ++i) {
            cin>>c[i];
            sum += c[i];
        }
        while (sum>0) {
            int p = -1,q = -1;
            find(p,q);
            if (p!=-1 && q!=-1) {
                sum -= 2;
                c[p]--; c[q]--;
                cout<<' '<<char('A'+p)<<char('A'+q);
            }
            else {
                find(p);
                assert(p!=-1);
                sum -= 1;
                c[p]--;
                cout<<' '<<char('A'+p);
            }
        }
        cout<<endl;
    }
    return 0;
}
