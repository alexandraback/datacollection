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


int a[2010];
int n,K;
int judge(long long x){
    int ret=n+1;
    long long s=0;
    for(int i=n-1;i>=0;i--){
        s+=x/a[i];
    }
    if(s<K)return ret=0;
    s=0;
    for(int i=0;i<n;i++){
        s+=(x-1)/a[i];
    }
    for(int i=0;i<n;i++){
        s+=x/a[i]-(x-1)/a[i];
        if(s>K)return ret=(i+1);
    }
    return 1;
}

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){
        scanf("%d%d",&n,&K);
        K--;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        long long l=0,r=1e15;
        //cout<<judge(28)<<endl;
        while(l+1<r){
            long long mid=(l+r)>>1;
            if(judge(mid))r=mid;
            else l=mid;
        }
        //cout<<r<<endl;
        printf("Case #%d: %d\n",_,judge(r));
    }
    return 0;
}
