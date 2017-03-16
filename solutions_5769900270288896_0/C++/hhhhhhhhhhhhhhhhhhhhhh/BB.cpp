#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

//rand()/(RAND_MAX+1.0)
//srand(time(0));
//

template <class T>
inline bool scan_d(T &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'|c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}

int r,c,K;
int mat[20][20];

int cal(){
    int ret=0;
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i-1][j]&&mat[i][j])ret++;
        }
    }
    for(int j=1;j<c;j++){
        for(int i=0;i<r;i++){
            if(mat[i][j-1]&&mat[i][j])ret++;
        }
    }
    return ret;
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){

        scanf("%d%d%d",&r,&c,&K);
        int tot=r*c;
        int ans=(1<<30);
        for(int i=0;i<(1<<tot);i++){
            if(__builtin_popcount(i)!=K)continue;
            memset(mat,0,sizeof(mat));
            for(int j=0;j<tot;j++){
                if((i>>j)&1){
                    mat[j/c][j%c]=1;
                }
            }
            ans=min(ans,cal());
        }
        printf("Case #%d: %d\n",_,ans);
    }
    return 0;
}
