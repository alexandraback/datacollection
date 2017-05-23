#include <cstdio>

using namespace std;

int T,n,m,num;
int x,ost,dva,tri,sol,sol2;

int main() {
    freopen("B-large.in","r",stdin);
    freopen("BBB2.out","w",stdout);
    scanf("%d",&T);
    for (int t=1; t<=T; t++) {
        scanf("%d %d %d",&n,&m,&num);
        if ((n*m+1)/2 >= num) {
            printf("Case #%d: 0\n",t);
            continue;
        }
        if (n==1 || m==1) {
            if (n*m%2==0) {
                x=n*m/2;
                ost=num-x;
                sol=1+(ost-1)*2;
            }
            else {
                x=n*m/2+1;
                ost=num-x;
                sol=ost*2;
            }
        }
        else {
        //neparno
        if (n*m % 2 == 1) {
            //gornji desni
            x=(n*m+1)/2;
            ost=num-x;
            tri=2*(n/2 + m/2);
            if (tri >= ost) sol=ost*3;
            else sol=tri*3+(ost-tri)*4;
            //ono drugo
            x=n*m/2;
            ost=num-x;
            dva=4;
            tri=2*(n/2+m/2)-4;
            if (dva>=ost) sol2=ost*2;
            else if (dva+tri>=ost) sol2=dva*2+(ost-dva)*3;
            else sol2=dva*2+tri*3+(ost-dva-tri)*4;
            if (sol2<sol) sol=sol2;
        }
        else {
            x=n*m/2;
            ost=num-x;
            tri=(n/2+(n+1)/2+m/2+(m+1)/2)-2-2;
            dva=2;
            if (dva>=ost) sol=ost*2;
            else if (dva+tri>=ost) sol=dva*2+(ost-dva)*3;
            else sol=dva*2+tri*3+(ost-dva-tri)*4;
        }
        }


        printf("Case #%d: %d\n",t,sol);
    }

    return 0;
}
