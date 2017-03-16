#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <set>

using namespace std;

int B,N;
int M[1013];
vector<int> can;

long long check(long long a) {
    long long cnt = 0;
    for (int i=0;i<B;i++) cnt+=a/M[i]+1;
    return cnt;
}

int main() {
    FILE* fin = fopen("B-large.in","r");
    FILE* fout = fopen("B-large.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for (int t=1;t<=T;t++) {
        fscanf(fin,"%d%d",&B,&N);
        for (int i=0;i<B;i++) fscanf(fin,"%d",&M[i]);
        if (N<=B) {
            fprintf(fout,"Case #%d: %d\n",t,N);
            continue;
        }
        long long low = -1;
        long long high = 1000000000000000000LL;
        while (high-low>1) {
            if (check((low+high+1)/2)>=N) high = (low+high+1)/2;
            else low = (low+high+1)/2;
        }
        can.clear();
        for (int i=0;i<B;i++) if (high%M[i]==0) can.push_back(i+1);
        fprintf(fout,"Case #%d: %d\n",t,can[N-(int) check(high-1)-1]);
    }

    return 0;
}
