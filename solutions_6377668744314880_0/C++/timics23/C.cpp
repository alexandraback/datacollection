#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int T,N,k,x[20],y[20],a[20],fix;
bool ok,v[20];
 
struct Punct {
    int x,y;
} rez[20], p[20], q[20];
 
inline long long cross(const Punct& A, const Punct& B, const Punct& C) {
    return 1LL*(B.x-A.x)*(C.y-A.y) - 1LL*(B.y-A.y)*(C.x-A.x);
}
 
inline int cmp(const Punct& A, const Punct&B) {
    return cross(q[1],A,B)<0;
}

inline bool colin(const Punct& A, const Punct&B, const Punct&C) {
    return cross(A,B,C) == 0;
}

bool convex_hull() {
    
    for(int i=1;i<=k;++i) {
        q[i] = p[a[i]];
    }

    int piv = 1;
    for(int i=2;i<=k;++i) {
        if((q[i].x<q[piv].x) || (q[i].x==q[piv].y && q[i].y<q[piv].y)) {
            piv=i;
        }
    }
    Punct temp = q[1];
    q[1] = q[piv];
    q[piv] = temp;
 
    sort(q+2,q+k+1,cmp);
 
    rez[1] = q[1];
    rez[2] = q[2];
    int head = 2;
 
    for(int i=3;i<=k;++i) {
        while(head>=2 && cross(rez[head - 1], rez[head], q[i])>0)
            --head;
        rez[++head] = q[i];
    }

    for(int i=1;i<=head;++i) {
        if(rez[i].x == p[fix].x && rez[i].y == p[fix].y) {
            return 1;
        }
    }
    for(int i=1;i<head;++i) {
        if(colin(rez[i],rez[i+1],p[fix])) {
            return 1;
        }
    }
    return 0;
}

void backy(int step) {
    if(step==k) {
        a[step] = fix;
        if(convex_hull()) {
            if(fix == 5) {
                /*for(int i=1;i<=step;++i) {
                    cout<<a[i]<<" ";
                }
                cout<<"\n";*/
            }
            ok = 1;
        }
    }
    else {
        for(int i=1;i<=N;++i) {
            if(i==fix) continue;
            if((v[i]==0)&&(i>a[step-1])) {
                a[step]=i;
                v[i]=1;
                backy(step+1);
                v[i]=0;
            }
        }
    }
}

int main() {
    freopen("input.in","r",stdin);
    freopen("outputC","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d:\n",t);
        scanf("%d",&N);
        for(int i=1;i<=N;++i) {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        if(N<=3) {
            for(int i=1;i<=N;++i) {
                printf("%d\n",0);
            }
            continue;
        }
        for(int i=1;i<=N;++i) {
            ok = 0;
            fix = i;
            for(int j=0;j<=N;++j) {
                k = N-j; // nr trees remaining
                backy(1);
                if(ok) {
                    printf("%d\n",j);
                    break;
                }
            }
        }
    }
    return 0;
}
