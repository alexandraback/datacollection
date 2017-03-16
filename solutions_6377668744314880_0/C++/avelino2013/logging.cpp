#include <bits/stdc++.h>
#define EPS 1e-6
using namespace std;

const int N=3e3+10;
int x[N], y[N];

//compara dois doubles, retornando 1 se x > y, 0 se x == y e -1 se x < y
int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }

//retorna um angulo entre 0 e 2*PI
double positive_angle(double a) {
    while(cmpD(a) < 0) a += 2*M_PI;
    while(cmpD(a, 2*M_PI) >= 0) a -= 2*M_PI;
    return a;
}

int main() {
    int n, t, T=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int nn=n;
        for(int i=0; i<nn; i++) scanf("%d %d", &x[i], &y[i]);
        printf("Case #%d:\n", T++);
        for(int i=0; i<nn; i++) {
            vector<double> v;
            for(int j=0; j<nn; j++) if(i!=j) v.push_back(positive_angle(atan2(y[j]-y[i], x[j]-x[i])));
            sort(v.begin(), v.end());
            n=(int)v.size();
            for(int j=0; j<n; j++) v.push_back(v[j]+2*M_PI);
            int aux=2*n, k=0, ans=nn;
            for(int j=0; j<n; j++) {
                for(; cmpD(v[k]-v[j], M_PI)==-1; k=(k+1)%aux);
                if(cmpD(v[k]-v[j], 2*M_PI)!=-1) {
                    ans=0;
                    break;
                }
                if(cmpD(v[k]-v[j], M_PI)!=-1) ans=min(ans, k-j-1);
                int val=k;
                for(; !cmpD(v[k]-v[val], M_PI); k=(k+1)%aux);
            }
            printf("%d\n", max(ans, 0));
        }
    }
    return 0;
}
