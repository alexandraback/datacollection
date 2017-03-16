#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long x[3013];
long long y[3013];
int ans[3013];

int main() {
    FILE* fin = fopen("C-small-attempt0.in","r");
    FILE* fout = fopen("C-small-attempt0.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for (int t=1;t<=T;t++) {
        fscanf(fin,"%d",&N);
        for (int i=0;i<N;i++) fscanf(fin,"%lld%lld",&x[i],&y[i]);
        for (int i=0;i<N;i++) ans[i] = N-1;
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (i==j) continue;
                int l = 0;
                int r = 0;
                for (int k=0;k<N;k++) {
                    long long cur = (y[i]-y[j])*(x[k]-x[j])+(x[j]-x[i])*(y[k]-y[j]);
                    if (cur<0) l+=1;
                    if (cur>0) r+=1;
                }
                ans[i] = min(ans[i],min(l,r));
            }
        }
        fprintf(fout,"Case #%d:\n",t);
        for (int i=0;i<N;i++) fprintf(fout,"%d\n",ans[i]);
    }

    return 0;
}
