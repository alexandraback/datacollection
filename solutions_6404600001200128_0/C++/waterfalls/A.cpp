#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int m[1000];

int main() {
    FILE* fin = fopen("A-small-attempt0.in","r");
    FILE* fout = fopen("A-small-attempt0.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for (int t=1;t<=T;t++) {
        fscanf(fin,"%d",&N);
        for (int i=0;i<N;i++) fscanf(fin,"%d",&m[i]);
        int y = 0;
        for (int i=1;i<N;i++) if (m[i]<m[i-1]) y+=m[i-1]-m[i];
        int z = 0;
        int pers = 0;
        for (int i=1;i<N;i++) if (m[i]<m[i-1]) pers = max(pers,m[i-1]-m[i]);
        for (int i=1;i<N;i++) z+=min(m[i-1],pers);
        fprintf(fout,"Case #%d: %d %d\n",t,y,z);
    }

    return 0;
}
